#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>
#include <dt-bindings/zmk/outputs.h>
#include "keys_de.h"

#define APT 0
#define NAV 1
#define NUM 2
#define SYM 3
#define MED 4
#define DE 4

#define QUICK_TAP_TIME 200

// &lt {
//     quick_tap_ms = <170>;
// };

&caps_word {
    continue-list = <UNDERSCORE MINUS BSPC LSHFT RSHFT>;
};


/ {
    combos {
        compatible = "zmk,combos";
/* usually on base layer */
        combo_q {
            timeout-ms = <40>;
            key-positions = <1 2>;
            bindings = <&kp Q>;
            layers = <APT>;
        };
        combo_z {
            timeout-ms = <40>;
            key-positions = <18 19>;
            bindings = <&kp DE_Z>;
        };
        combo_v {
            timeout-ms = <40>;
            key-positions = <0 1>;
            bindings = <&kp V>;
            layers = <APT>;
        };
        combo_slash {
            timeout-ms = <40>;
            key-positions = <22 23>;
            bindings = <&kp SLASH>;
        };
        combo_ent {
            timeout-ms = <40>;
            key-positions = <21 22>;
            bindings = <&kp ENTER>;
        };
/* caps */
        combo_caps-word {
            timeout-ms = <40>;
            key-positions = <11 14>;
            bindings = <&caps_word>;
        };
        combo_capslock {
            timeout-ms = <40>;
            key-positions = <0 7>;
            bindings = <&kp CAPSLOCK>;
        };
        /* Umlaute */
        combo_ue {
          timeout-ms = <20>;
          key-positions = <7 26>;
          bindings = <&kp DE_UE>;
        };
        combo_oe {
          timeout-ms = <20>;
          key-positions = <17 26>;
          bindings = <&kp DE_OE>;
        };
        combo_ae {
          timeout-ms = <20>;
          key-positions = <15 26>;
          bindings = <&kp DE_AE>;
        };
        combo_sz {
          timeout-ms = <20>;
          key-positions = <9 26>;
          bindings = <&kp DE_SZ>;
        };
        /* deletion */
        combo_bspc {
          timeout-ms = <40>;
          key-positions = <5 6>;
            bindings = <&kp BSPC>;
        };
        combo_del {
            timeout-ms = <40>;
            key-positions = <6 7>;
            bindings = <&kp DEL>;
        };
        combo_delword {
            timeout-ms = <40>;
            key-positions = <5 7>;
            bindings = <&kp LC(BSPC)>;
        };
/*F keys*/
        combo_F1 {
          timeout-ms = <40>;
          key-positions = <0 1>;
          layers = <NUM>;
          bindings = <&kp F1>;
        };
        combo_F9 {
          timeout-ms = <40>;
          key-positions = <18 19>;
          layers = <NUM>;
          bindings = <&kp F9>;
        };
    };
};


/ {

    behaviors {
        hl: homerow_mods_left {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods left";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <4 5 6 7 13 14 15 16 17 21 22 23 24 25 26 27>;
        };
        hr: homerow_mods_right {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods right";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&kp>, <&kp>;
            // opposite side hand keys
            hold-trigger-key-positions = <0 1 2 3 8 9 10 11 12 18 19 20 24 25 26 27>;
        };

        my_lt: my_layer_taps {
            compatible = "zmk,behavior-hold-tap";
            label = "my layer taps";
            #binding-cells = <2>;
            // flavor = "tap-preferred";
            flavor = "balanced";
            tapping-term-ms = <150>;
            quick-tap-ms = <QUICK_TAP_TIME>;
            // global-quick-tap;
            bindings = <&mo &kp>, <&kp>;
            // non-thumb keys
            hold-trigger-key-positions = <0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27>;
        };

        dotcol: dot_colon {
            compatible = "zmk,behavior-mod-morph";
            label = "DOT_COL";
            #binding-cells = <0>;
            bindings = <&kp DOT>, <&kp COLON>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
        comsem: comma_semicolon {
            compatible = "zmk,behavior-mod-morph";
            label = "COM_SEM";
            #binding-cells = <0>;
            bindings = <&kp COMMA>, <&kp SEMI>;
            mods = <(MOD_LSFT|MOD_RSFT)>;
        };
    };
};
