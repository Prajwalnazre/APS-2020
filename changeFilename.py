import os

# Create a list of files from the current directory who's last 4 characters
# as lowercase are either '.jpg' or '.png'
files = [ f for f in os.listdir('.') if f[-4:].lower() in ('.jpg') ]

DRYRUN=True

for (index,filename) in enumerate(files):
  extension = os.path.splitext(filename)[1]
  newname = "image_%d%s" % (index,extension)
  if os.path.exists(newname):
    print("Cannot rename %s"%filename) 
    #print("Cannot rename %s to %s, already exists" % filename % newname) 
    continue
  if DRYRUN:
    print("Would rename %s"%filename)
    #print("Would rename %s to %s" % filename % newname) 
  else:
    print("Renaming %s to %s" % filename % newname) 
  os.rename(filename,newname)
