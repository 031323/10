ep=Environment(COMPILATIONDB_USE_ABSPATH=True,CCFLAGS='-g -Wall')
ep.ParseConfig('pkg-config --cflags --libs sdl2')
ep.Tool('compilation_db')
ep.CompilationDatabase()
ep.Program('yt',Glob('3.cpp'))
djts=ARGUMENTS.get('jts')
jts='/usr/'
if type(djts)==str:
    jts=djts
ep.Program('mr','8.cpp',LIBS=['wasmtime'],LIBPATH=[jts+'/lib'],CCFLAGS=['-I'+jts+'/include'])
