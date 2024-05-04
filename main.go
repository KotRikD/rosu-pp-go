package main

/*
#cgo LDFLAGS: -L./lib -lrosu_pp_ffi
#include "./lib/rosu_pp_ffi.h"
#include <stdlib.h>
*/
import "C"

import (
	"fmt"
	"unsafe"
)

type ScoreParams struct {
	mode          uint
	mods          uint
	acc           float64
	n300          uint
	n100          uint
	n50           uint
	nMisses       uint
	nKatu         uint
	combo         uint
	score         uint
	passedObjects uint
	clockRate     float64
}

type RosuCalculator struct {
	mapPath     string
	scoreParams ScoreParams
}

func (rosu RosuCalculator) Calculate() C.calculateresult {
	cMapPath := C.CString(rosu.mapPath)
	defer C.free(unsafe.Pointer(cMapPath))

	var calculator *C.calculator
	C.calculator_new(&calculator, cMapPath)
	// C.calculator_new_from_data(&calculator, cMapDataInString)
	defer C.calculator_destroy(&calculator)

	var scoreParams *C.scoreparams
	C.score_params_new(&scoreParams)
	C.score_params_mode(scoreParams, C.mode(rosu.scoreParams.mode))
	if rosu.scoreParams.mods > 0 {
		C.score_params_mods(scoreParams, C.uint(rosu.scoreParams.mods))
	}
	if rosu.scoreParams.acc > 0 {
		C.score_params_acc(scoreParams, C.double(rosu.scoreParams.acc))
	}
	if rosu.scoreParams.n300 > 0 {
		C.score_params_n300(scoreParams, C.uint(rosu.scoreParams.n300))
	}
	if rosu.scoreParams.n100 > 0 {
		C.score_params_n100(scoreParams, C.uint(rosu.scoreParams.n100))
	}
	if rosu.scoreParams.n50 > 0 {
		C.score_params_n50(scoreParams, C.uint(rosu.scoreParams.n50))
	}
	if rosu.scoreParams.combo > 0 {
		C.score_params_combo(scoreParams, C.uint(rosu.scoreParams.combo))
	}
	if rosu.scoreParams.nMisses > 0 {
		C.score_params_n_misses(scoreParams, C.uint(rosu.scoreParams.nMisses))
	}
	if rosu.scoreParams.nKatu > 0 {
		C.score_params_n_katu(scoreParams, C.uint(rosu.scoreParams.nKatu))
	}
	if rosu.scoreParams.passedObjects > 0 {
		C.score_params_passed_objects(scoreParams, C.uint(rosu.scoreParams.nKatu))
	}
	if rosu.scoreParams.clockRate > 0 {
		C.score_params_clock_rate(scoreParams, C.double(rosu.scoreParams.clockRate))
	}
	defer C.score_params_destroy(&scoreParams)

	calculationResult := C.calculator_calculate(calculator, scoreParams)
	return calculationResult
}

func main() {
	calculator := RosuCalculator{
		mapPath: "./test.osu",
		scoreParams: ScoreParams{
			mode:    0,
			n300:    372,
			n100:    8,
			n50:     0,
			nMisses: 0,
			acc:     98.60,
			combo:   542,
			mods:    72,
		},
	}
	result := calculator.Calculate()
	fmt.Println(result.stars)
	fmt.Println(result.pp)
}
