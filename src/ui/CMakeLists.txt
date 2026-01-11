SET(SOURCES components/ui_comp_switchbutton.c
    components/ui_comp.c
    screens/ui_ScrMenu.c
    screens/ui_ScrSettings.c
    screens/ui_ScrGaugeSingle.c
    screens/ui_ScrSwitch.c
    screens/ui_ScrChangeName.c
    screens/ui_ScreenCalib.c
    screens/ui_ScrNumKey.c
    screens/ui_ScreenGaugeMulti.c
    screens/ui_ScrPeers.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    ui_events.cpp
    images/ui_img_bg_grill_png.c
    images/ui_img_icon_settings_png.c
    images/ui_img_icon_gauge_png.c
    images/ui_img_icon_switch_png.c
    images/ui_img_icon_pair_off_png.c
    images/ui_img_icon_pair_png.c
    images/ui_img_icon_keyboard_png.c
    images/ui_img_icon_calib_png.c
    images/ui_img_1825836894.c
    images/ui_img_551600910.c
    images/ui_img_gauge_leer_240_png.c
    images/ui_img_toggle_vertical_off_75_png.c
    images/ui_img_toggle_vertical_on_75_png.c
    images/ui_img_toggle_vertical_off_75_png.c
    images/ui_img_toggle_vertical_on_75_png.c
    images/ui_img_gauge_leer_100_png.c)

add_library(ui ${SOURCES})
