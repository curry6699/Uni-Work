 #!/bin/dash
PATH="$PATH:."

snapshot-save.sh

snapshotVersion="$1"
snapshotPath=".snapshot.$snapshotVersion"

echo "Restoring snapshot $1"

for file in "$snapshotPath/"*
do
    cp "$file" "."
done