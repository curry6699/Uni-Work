#!/bin/dash

for arg in "$@" 
do
    display "$arg"
    read -p "Address to e-mail this image to? " email
    read -p "Message to accompany image? " message
    echo "$arg sent to $email"

    echo "$message" | mutt -s "Labs" -e 'set copy=no' -a "$arg" -- "$email"
    
done