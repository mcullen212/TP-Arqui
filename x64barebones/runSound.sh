if [ "$(uname)" == "Darwin" ]; then
    audio="coreaudio"
else
    audio="pa"
fi
qemu-system-x86_64 -hda Image/x64BareBonesImage.qcow2 -m 512 -audiodev $audio,id=audio0 -machine pcspk-audiodev=audio0
