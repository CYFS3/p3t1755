from building import *
Import('rtconfig')

src   = []
cwd   = GetCurrentDir()

src += Glob('p3t1755.c')


if GetDepend('PKG_P3T1755_USING_SENSOR_V2'):
    src += ['nxp_p3t1755_sensor_v2.c']

# add p3t1755 include path.
path  = [cwd]

# add src and include to group.
group = DefineGroup('p3t1755', src, depend = ['PKG_USING_P3T1755'], CPPPATH = path)

Return('group')
