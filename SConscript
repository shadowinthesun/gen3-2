import fnmatch
import os

Import('*')

exclude_paths = set(['Cell_Management_System','Driver','AA','BA','BB','BC','BD','BE','BF','BG','CC','CB','CD','CHA','GA','GB','KA','RA','SA','TS','WA','WB','XA'])
exclude_paths2 = set (['Analysis', 'Archive','CodeGenModels','GotionLibrary','SimulationModels','Tools'])

objects = []
sources = []
includes = []

cwd = os.getcwd()   


# Get Gen Files Files
cwd = os.path.join(cwd,'../')
cwd = os.path.normpath(cwd)
Gen_Path = os.path.join(cwd, env.subst('$GEN_PROJ') )
#print('Gen_Path is  ' + Gen_Path )

for root, dirnames, filenames in os.walk( Gen_Path, topdown=True ):
    # Exclude directories by name
    dirnames[:] = [d for d in dirnames if d not in exclude_paths]
    dirnames[:] = [d for d in dirnames if d not in exclude_paths2]

    # Specifically exclude bin directories inside the ISOLAR directory
    if (root.lower().endswith("isolar")):
        dirnames[:] = [d for d in dirnames if d not in ['BIN', 'Bin', 'bin']]
        
    # Specifically exclude  directories inside the SCUR_A2 directory
    if (root.lower().endswith("SCUR_A2")):
        dirnames[:] = [d for d in dirnames if d not in exclude_paths2]
   

    # Sources
    for filename in fnmatch.filter(filenames, '*.c'):
        sources += Glob(root + '/*.c')
        break

    # Headers
    for filename in fnmatch.filter(filenames, '*.h'):
        includes.append(root)
        break


# ADD INCLUDE DIRECTORIES
for include in includes:
    if (".metadata" not in include):
        env.Append(CPPPATH=[Dir(include).abspath])

# COMPILER SOURCE FILE
for source in sources:
    objects += env.Object(source)

# RETURN
Return('objects')
