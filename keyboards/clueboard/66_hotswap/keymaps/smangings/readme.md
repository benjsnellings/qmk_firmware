   _____ __  ______    _   _______________________
  / ___//  |/  /   |  / | / / ____/  _/ ____/ ___/
  \__ \/ /|_/ / /| | /  |/ / / __ / // / __ \__ \
 ___/ / /  / / ___ |/ /|  / /_/ // // /_/ /___/ /
/____/_/  /_/_/  |_/_/ |_/\____/___/\____//____/


# Smangings Clueboard 66% Hotswap Layout

This layout was made specifcally to add some power user features, and a few bells and whistles just for fun.



## How to flash

make clueboard/66_hotswap/gen1:smangings

dfu-util -a 0 -d 0482:df11 -s 0x8000000:leave -D /Users/benjaminsnellings/Documents/Workplace/QMK/qmk_firmware/clueboard_66_hotswap_gen1_smangings.bin

