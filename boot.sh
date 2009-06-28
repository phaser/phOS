#!/bin/sh

#MYKERN=newkern/kImage
MYKERN=phOS.img

rm -f grub.iso
if [ -e "$MYKERN" ]; then
	echo "Copying kernel..."
	cp -v $MYKERN bin/kernel
fi

echo "Making image..."
mkisofs -R -b boot/grub/stage2_eltorito -no-emul-boot -boot-load-size 4 -boot-info-table -o grub.iso bin

echo $1
if [ "$1" = "qemu" ]; then
	echo "Booting... in QEMU"
	qemu -no-kqemu -s -cdrom grub.iso -boot d
else
	echo "Booting... in Bochs"
	bochs -f bochs.cfg
fi
