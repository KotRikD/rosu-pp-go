// Automatically generated by Interoptopus.

#ifndef rosu_pp
#define rosu_pp

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>




typedef enum mode
    {
    /// osu!standard
    MODE_OSU = 0,
    /// osu!taiko
    MODE_TAIKO = 1,
    /// osu!catch
    MODE_CATCH = 2,
    /// osu!mania
    MODE_MANIA = 3,
    } mode;

typedef struct calculator calculator;

typedef struct scoreparams scoreparams;

typedef enum ffierror
    {
    FFIERROR_OK = 0,
    FFIERROR_NULL = 100,
    FFIERROR_PANIC = 200,
    FFIERROR_FAIL = 300,
    } ffierror;

///Option type containing boolean flag and maybe valid data.
typedef struct optionf64
    {
    ///Element that is maybe valid.
    double t;
    ///Byte where `1` means element `t` is valid.
    uint8_t is_some;
    } optionf64;

///Option type containing boolean flag and maybe valid data.
typedef struct optionu32
    {
    ///Element that is maybe valid.
    uint32_t t;
    ///Byte where `1` means element `t` is valid.
    uint8_t is_some;
    } optionu32;

typedef struct calculateresult
    {
    uint8_t mode;
    double stars;
    double pp;
    optionf64 ppAcc;
    optionf64 ppAim;
    optionf64 ppFlashlight;
    optionf64 ppSpeed;
    optionf64 ppStrain;
    optionu32 nFruits;
    optionu32 nDroplets;
    optionu32 nTinyDroplets;
    optionf64 aimStrain;
    optionf64 speedStrain;
    optionf64 flashlightRating;
    optionf64 sliderFactor;
    optionf64 ppDifficulty;
    optionf64 effectiveMissCount;
    double ar;
    double cs;
    double hp;
    double od;
    double bpm;
    double clockRate;
    optionf64 timePreempt;
    optionf64 greatHitWindow;
    optionu32 nObjects;
    optionu32 nSliders;
    optionu32 nSpinners;
    optionu32 maxCombo;
    } calculateresult;


/// Destroys the given instance.
///
/// # Safety
///
/// The passed parameter MUST have been created with the corresponding init function;
/// passing any other value results in undefined behavior.
ffierror calculator_destroy(calculator** context);

ffierror calculator_new(calculator** context, const char* beatmap_path);

calculateresult calculator_calculate(calculator* context, const scoreparams* score_params);

/// Destroys the given instance.
///
/// # Safety
///
/// The passed parameter MUST have been created with the corresponding init function;
/// passing any other value results in undefined behavior.
ffierror score_params_destroy(scoreparams** context);

/// 构造一个params
ffierror score_params_new(scoreparams** context);

void score_params_mode(scoreparams* context, mode mode);

void score_params_mods(scoreparams* context, uint32_t mods);

void score_params_acc(scoreparams* context, double acc);

void score_params_n300(scoreparams* context, uint32_t n300);

void score_params_n100(scoreparams* context, uint32_t n100);

void score_params_n50(scoreparams* context, uint32_t n50);

void score_params_combo(scoreparams* context, uint32_t combo);

void score_params_score(scoreparams* context, uint32_t score);

void score_params_n_misses(scoreparams* context, uint32_t n_misses);

void score_params_n_katu(scoreparams* context, uint32_t n_katu);

void score_params_passed_objects(scoreparams* context, uint32_t passed_objects);

void score_params_clock_rate(scoreparams* context, double clock_rate);


#ifdef __cplusplus
}
#endif

#endif /* rosu_pp */
