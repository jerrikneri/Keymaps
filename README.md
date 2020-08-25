Repo at ~/Keyboard/keymaps

ln -s ~/Keyboard/keymaps/letssplit ~/Keyboard/qmk/keyboards/lets_split/keymaps/jerrik

ln -s  ~/Keyboard/keymaps/planck ~/Keyboard/qmk/keyboards/planck/keymaps/jerrik

make clean

make lets_split/rev2:jerrik:avrdude

make make planck/rev4:jerrik:dfu