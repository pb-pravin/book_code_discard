import sys, traceback
traceOutput = sys.stdout
watchOutput = sys.stdout
rawOutput = sys.stdout
# calling 'watch(secretOfUniverse)' prints out something like:
# File "trace.py", line 57, in __testTrace
#    secretOfUniverse <int> = 42
watch_format = ('File "%(fileName)s", line %(lineNumber)d, in' 
                ' %(methodName)s\n   %(varName)s <%(varType)s>' 
                ' = %(value)s\n\n')
def watch(variableName):
    if __debug__:
        stack = traceback.extract_stack()[-2:][0]
        actualCall = stack[3]
        if actualCall is None:
            actualCall = "watch([unknown])"
        left = actualCall.find('(')
        right = actualCall.rfind(')')
        paramDict = dict(varName=actualCall[left+1:right]).strip(),
                         varType=str(type(variableName))[7:-2],
                         value=repr(variableName),
                         methodName=stack[2],
                         lineNumber=stack[1],
                         fileName=stack[0])
        watchOutput.write(watch_format % paramDict)
# calling 'trace("this line was executed")' prints out something like:
# File "trace.py", line 64, in ?
#    this line was executed
trace_format = ('File "%(fileName)s", line %(lineNumber)d, in' 
                ' %(methodName)s\n   %(text)s\n\n')
def trace(text):
    if __debug__:
        stack = traceback.extract_stack()[-2:][0]
        paramDict = dict(text=text,
                         methodName=stack[2],
                         lineNumber=stack[1],
                         fileName=stack[0])
        watchOutput.write(trace_format % paramDict)
# calling 'raw("some raw text")' prints out something like:
# Just some raw text
def raw(text):
    if __debug__:
        rawOutput.write(text)
