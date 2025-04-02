from pymsl import MSL
import pprint
import os

os.environ['CTYPES_VERBOSE'] = '1'


msl = MSL('./msl-compiler/bin/libMSL.dll')
#msl = MSL('C:\\Users\\mrybs\\Desktop\\msl\\msl-compiler\\bin\\libMSL.dll')
#msl = MSL('./libMSL.dll')
u = msl.tokenize("""

""")
pprint.pprint(u)