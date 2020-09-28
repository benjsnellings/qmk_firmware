   _____ __  ______    _   _______________________
  / ___//  |/  /   |  / | / / ____/  _/ ____/ ___/
  \__ \/ /|_/ / /| | /  |/ / / __ / // / __ \__ \
 ___/ / /  / / ___ |/ /|  / /_/ // // /_/ /___/ /
/____/_/  /_/_/  |_/_/ |_/\____/___/\____//____/


# Smangings Clueboard 66% Hotswap Layout

This layout was made specifcally to add some power user features, and a few bells and whistles just for fun.

# Way to visualize

http://ciantic.github.io/keymapceditor/#||


[visualize whatever is checked in](ciantic.github.io/keymapceditor/#clueboard/66_hotswap||https%3A%2F%2Fraw.githubusercontent.com%2Fbenjsnellings%2Fqmk_firmware%2Fsmangings%2Fkeyboards%2Fclueboard%2F66_hotswap%2Fkeymaps%2Fsmangings%2Fkeymap.c)

## How to flash

make clueboard/66_hotswap/gen1:smangings

dfu-util -a 0 -d 0482:df11 -s 0x8000000:leave -D /Users/benjaminsnellings/Documents/Workplace/QMK/qmk_firmware/clueboard_66_hotswap_gen1_smangings.bin

