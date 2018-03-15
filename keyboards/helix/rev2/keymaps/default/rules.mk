
# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no       # Mouse keys(+4700)
EXTRAKEY_ENABLE = no       # Audio control and System control(+450)
CONSOLE_ENABLE = no         # Console for debug(+400)
COMMAND_ENABLE = no        # Commands for debug and configuration
NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
# Helix keyboard :
#     LED off                 : make helix:default
#     LED backlight           : make LED=back   helix:default
#           and no animations : make LED=backna helix:default
#     LED underglow           : make LED=under   helix:default
#           and no animetions : make LED=underna helix:default
#  see ./config.h
RGBLED := $(filter back backna under underna,$(LED) $(RGBLED))
ifeq ($(RGBLED),)
  ifneq ($(LED),)
    $(warning === Unknown keyword! : LED=$(LED) ===)
    $(error try : make helix:default:help ***)
  endif
endif
ifneq ($(RGBLED),)
  RGBLIGHT_ENABLE = yes   # Enable WS2812 RGB underlight.  Do not enable this with audio at the same time.
  ifeq ($(strip $(RGBLED)), under)
    OPT_DEFS += -DRGBLED=1
  endif
  ifeq ($(strip $(RGBLED)), underna)
    OPT_DEFS += -DRGBLED=2
  endif
  ifeq ($(strip $(RGBLED)), back)
    OPT_DEFS += -DRGBLED=3
  endif
  ifeq ($(strip $(RGBLED)), backna)
    OPT_DEFS += -DRGBLED=4
  endif
endif
ONEHAND_ENABLE = no        # Enable one-hand typing

# Helix keyboard :
#     OLED off  : make helix:default
#     OLED on   : make OLED=yes helix:default
OLEDSW := $(filter yes on,$(OLED))
ifneq ($(strip $(OLEDSW)),)
    OPT_DEFS += -DOLED_ENABLE
else
  ifneq ($(OLED),)
    $(warning === Unknown keyword! : OLED=$(OLED) ===)
    $(error try : make helix:default:help ***)
  endif
endif

help:
	echo "OLED off, RGBRIGHT off:       $$ make helix:default"
	echo "OLED on,  RGBRIGHT off:       $$ make OLED=yes    helix:default"
	echo "OLED off, RGBRIGHT underglow: $$ make LED=under   helix:default"
	echo "        and no animation    : $$ make LED=underna helix:default"
	echo "OLED off, RGBRIGHT backlight: $$ make LED=back    helix:default"
	echo "        and no animation    : $$ make LED=backna  helix:default"
	echo "OLED on,  RGBRIGHT backlight: $$ make OLED=yes LED=back   helix:default"
	echo "        and no animation    : $$ make OLED=yes LED=backna helix:default"
	echo ""
	exit 0

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

ifndef QUANTUM_DIR
	include ../../../../Makefile
endif
