cmake_minimum_required(VERSION 3.14)

project(TuneIt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)

set(PROJECT_SOURCES
        main.cpp
        qml.qrc
        fftfilterprocessor.cpp
)

set(CMAKE_EXE_LINKER_FLAGS -fuse-ld=mold)

set(FFTW3_ROOT_DIR /home/ben/Downloads/fftw-3.3.10)
include_directories(${FFTW3_ROOT_DIR})

set(RTAUDIO_SOURCES RtAudio.cpp)

set(FFTW3_API_SOURCES
        ${FFTW3_ROOT_DIR}/api/execute-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/rdft2-pad.c
        ${FFTW3_ROOT_DIR}/api/import-wisdom-from-string.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-r2c-2d.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-r2c-1d.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-c2r-1d.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/version.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-r2r.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-split-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/import-system-wisdom.c
        ${FFTW3_ROOT_DIR}/api/execute-split-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-2d.c
        ${FFTW3_ROOT_DIR}/api/f77api.c
        ${FFTW3_ROOT_DIR}/api/plan-many-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-many-r2r.c
        ${FFTW3_ROOT_DIR}/api/map-r2r-kind.c
        ${FFTW3_ROOT_DIR}/api/import-wisdom.c
        ${FFTW3_ROOT_DIR}/api/mkprinter-str.c
        ${FFTW3_ROOT_DIR}/api/the-planner.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-r2r-3d.c
        ${FFTW3_ROOT_DIR}/api/plan-r2r.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/export-wisdom-to-string.c
        ${FFTW3_ROOT_DIR}/api/plan-dft.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-split-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-split-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-split-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/plan-r2r-2d.c
        ${FFTW3_ROOT_DIR}/api/mktensor-iodims.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-r2r.c
        ${FFTW3_ROOT_DIR}/api/export-wisdom.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-dft.c
        ${FFTW3_ROOT_DIR}/api/import-wisdom-from-file.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-dft.c
        ${FFTW3_ROOT_DIR}/api/apiplan.c
        ${FFTW3_ROOT_DIR}/api/flops.c
        ${FFTW3_ROOT_DIR}/api/configure.c
        ${FFTW3_ROOT_DIR}/api/malloc.c
        ${FFTW3_ROOT_DIR}/api/execute-split-dft.c
        ${FFTW3_ROOT_DIR}/api/execute-r2r.c
        ${FFTW3_ROOT_DIR}/api/plan-many-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-dft-c2r.c
        ${FFTW3_ROOT_DIR}/api/print-plan.c
        ${FFTW3_ROOT_DIR}/api/mkprinter-file.c
        ${FFTW3_ROOT_DIR}/api/plan-guru64-split-dft.c
        ${FFTW3_ROOT_DIR}/api/execute-split-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/export-wisdom-to-file.c
        ${FFTW3_ROOT_DIR}/api/execute-dft-r2c.c
        ${FFTW3_ROOT_DIR}/api/plan-r2r-1d.c
        ${FFTW3_ROOT_DIR}/api/forget-wisdom.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-3d.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-1d.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-c2r-3d.c
        ${FFTW3_ROOT_DIR}/api/execute-dft.c
        ${FFTW3_ROOT_DIR}/api/plan-guru-split-dft.c
        ${FFTW3_ROOT_DIR}/api/plan-many-dft.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-c2r-2d.c
        ${FFTW3_ROOT_DIR}/api/mktensor-rowmajor.c
        ${FFTW3_ROOT_DIR}/api/mapflags.c
        ${FFTW3_ROOT_DIR}/api/plan-dft-r2c-3d.c
        ${FFTW3_ROOT_DIR}/api/execute.c
        ${FFTW3_ROOT_DIR}/api/mktensor-iodims64.c
        )
set(FFTW3_KERNEL_SOURCES
        ${FFTW3_ROOT_DIR}/kernel/cpy2d.c
        ${FFTW3_ROOT_DIR}/kernel/hash.c
        ${FFTW3_ROOT_DIR}/kernel/cpy1d.c
        ${FFTW3_ROOT_DIR}/kernel/print.c
        ${FFTW3_ROOT_DIR}/kernel/alloc.c
        ${FFTW3_ROOT_DIR}/kernel/tensor2.c
        ${FFTW3_ROOT_DIR}/kernel/tile2d.c
        ${FFTW3_ROOT_DIR}/kernel/problem.c
        ${FFTW3_ROOT_DIR}/kernel/md5.c
        ${FFTW3_ROOT_DIR}/kernel/md5-1.c
        ${FFTW3_ROOT_DIR}/kernel/solver.c
        ${FFTW3_ROOT_DIR}/kernel/timer.c
        ${FFTW3_ROOT_DIR}/kernel/tensor9.c
        ${FFTW3_ROOT_DIR}/kernel/tensor8.c
        ${FFTW3_ROOT_DIR}/kernel/tensor4.c
        ${FFTW3_ROOT_DIR}/kernel/assert.c
        ${FFTW3_ROOT_DIR}/kernel/ops.c
        ${FFTW3_ROOT_DIR}/kernel/solvtab.c
        ${FFTW3_ROOT_DIR}/kernel/scan.c
        ${FFTW3_ROOT_DIR}/kernel/plan.c
        ${FFTW3_ROOT_DIR}/kernel/tensor3.c
        ${FFTW3_ROOT_DIR}/kernel/twiddle.c
        ${FFTW3_ROOT_DIR}/kernel/buffered.c
        ${FFTW3_ROOT_DIR}/kernel/trig.c
        ${FFTW3_ROOT_DIR}/kernel/cpy2d-pair.c
        ${FFTW3_ROOT_DIR}/kernel/primes.c
        ${FFTW3_ROOT_DIR}/kernel/debug.c
        ${FFTW3_ROOT_DIR}/kernel/tensor7.c
        ${FFTW3_ROOT_DIR}/kernel/tensor1.c
        ${FFTW3_ROOT_DIR}/kernel/rader.c
        ${FFTW3_ROOT_DIR}/kernel/tensor.c
        ${FFTW3_ROOT_DIR}/kernel/ct.c
        ${FFTW3_ROOT_DIR}/kernel/pickdim.c
        ${FFTW3_ROOT_DIR}/kernel/planner.c
        ${FFTW3_ROOT_DIR}/kernel/tensor5.c
        ${FFTW3_ROOT_DIR}/kernel/kalloc.c
        ${FFTW3_ROOT_DIR}/kernel/iabs.c
        ${FFTW3_ROOT_DIR}/kernel/extract-reim.c
        ${FFTW3_ROOT_DIR}/kernel/align.c
        ${FFTW3_ROOT_DIR}/kernel/stride.c
        ${FFTW3_ROOT_DIR}/kernel/awake.c
        ${FFTW3_ROOT_DIR}/kernel/minmax.c
        ${FFTW3_ROOT_DIR}/kernel/transpose.c
        )
set(FFTW3_THREADS_SOURCES
        ${FFTW3_ROOT_DIR}/threads/hc2hc.c
        ${FFTW3_ROOT_DIR}/threads/f77api.c
#        ${FFTW3_ROOT_DIR}/threads/openmp.c
        ${FFTW3_ROOT_DIR}/threads/dft-vrank-geq1.c
        ${FFTW3_ROOT_DIR}/threads/api.c
        ${FFTW3_ROOT_DIR}/threads/ct.c
        ${FFTW3_ROOT_DIR}/threads/conf.c
        ${FFTW3_ROOT_DIR}/threads/rdft-vrank-geq1.c
        ${FFTW3_ROOT_DIR}/threads/threads.c
        ${FFTW3_ROOT_DIR}/threads/vrank-geq1-rdft2.c
        )
set(FFTW3_REODFT_SOURCES
        ${FFTW3_ROOT_DIR}/reodft/redft00e-r2hc-pad.c
        ${FFTW3_ROOT_DIR}/reodft/reodft11e-r2hc-odd.c
        ${FFTW3_ROOT_DIR}/reodft/reodft00e-splitradix.c
        ${FFTW3_ROOT_DIR}/reodft/reodft010e-r2hc.c
        ${FFTW3_ROOT_DIR}/reodft/redft00e-r2hc.c
        ${FFTW3_ROOT_DIR}/reodft/rodft00e-r2hc.c
        ${FFTW3_ROOT_DIR}/reodft/rodft00e-r2hc-pad.c
        ${FFTW3_ROOT_DIR}/reodft/conf.c
        ${FFTW3_ROOT_DIR}/reodft/reodft11e-radix2.c
        ${FFTW3_ROOT_DIR}/reodft/reodft11e-r2hc.c
        )
set(FFTW3_DFT_SOURCES
        ${FFTW3_ROOT_DIR}/dft/problem.c
        ${FFTW3_ROOT_DIR}/dft/direct.c
        ${FFTW3_ROOT_DIR}/dft/solve.c
        ${FFTW3_ROOT_DIR}/dft/rank-geq2.c
        ${FFTW3_ROOT_DIR}/dft/generic.c
        ${FFTW3_ROOT_DIR}/dft/dftw-direct.c
        ${FFTW3_ROOT_DIR}/dft/zero.c
        ${FFTW3_ROOT_DIR}/dft/dftw-generic.c
        ${FFTW3_ROOT_DIR}/dft/scalar/t.c
        ${FFTW3_ROOT_DIR}/dft/scalar/n.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_20.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_12.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_7.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_4.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_4.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_6.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_2.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_3.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_16.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_25.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_20.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_12.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/codlist.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_25.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_25.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_6.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_20.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_6.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_11.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_5.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_14.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_9.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_5.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_8.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_8.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_32.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_2.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_10.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_16.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_2.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_3.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_64.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_15.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_7.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_64.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_32.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_9.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_5.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_16.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_32.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_13.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_15.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_8.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_10.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_10.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_5.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/q1_3.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t1_4.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_64.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/n1_4.c
        ${FFTW3_ROOT_DIR}/dft/scalar/codelets/t2_8.c
        ${FFTW3_ROOT_DIR}/dft/bluestein.c
        ${FFTW3_ROOT_DIR}/dft/dftw-directsq.c
        ${FFTW3_ROOT_DIR}/dft/indirect-transpose.c
        ${FFTW3_ROOT_DIR}/dft/plan.c
        ${FFTW3_ROOT_DIR}/dft/buffered.c
        ${FFTW3_ROOT_DIR}/dft/dftw-genericbuf.c
        ${FFTW3_ROOT_DIR}/dft/kdft.c
        ${FFTW3_ROOT_DIR}/dft/rader.c
        ${FFTW3_ROOT_DIR}/dft/vrank-geq1.c
        ${FFTW3_ROOT_DIR}/dft/ct.c
        ${FFTW3_ROOT_DIR}/dft/conf.c
        ${FFTW3_ROOT_DIR}/dft/kdft-dif.c
        ${FFTW3_ROOT_DIR}/dft/kdft-difsq.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/sse2/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/common/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/kcvi/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx512/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx-128-fma/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/neon/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/altivec/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2-128/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd128/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/generic-simd256/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/vsx/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx/t2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/codlist.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/genus.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2sv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2sv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2sv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1sv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_13.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_6.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_11.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_25.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2sv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_32.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1fv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2sv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/q1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_7.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_16.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_9.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_5.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_15.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2bv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_14.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_2.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fuv_4.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1bv_12.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1buv_3.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1bv_128.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t3fv_10.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n1fv_64.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/n2fv_8.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t1fv_20.c
#        ${FFTW3_ROOT_DIR}/dft/simd/avx2/t2fv_16.c
        ${FFTW3_ROOT_DIR}/dft/indirect.c
        ${FFTW3_ROOT_DIR}/dft/nop.c
        ${FFTW3_ROOT_DIR}/dft/kdft-dit.c
        )
set(FFTW3_RDFT_SOURCES
        ${FFTW3_ROOT_DIR}/rdft/rdft2-inplace-strides.c
        ${FFTW3_ROOT_DIR}/rdft/rdft-dht.c
        ${FFTW3_ROOT_DIR}/rdft/plan2.c
        ${FFTW3_ROOT_DIR}/rdft/dht-rader.c
        ${FFTW3_ROOT_DIR}/rdft/problem2.c
        ${FFTW3_ROOT_DIR}/rdft/kr2r.c
        ${FFTW3_ROOT_DIR}/rdft/hc2hc.c
        ${FFTW3_ROOT_DIR}/rdft/buffered2.c
        ${FFTW3_ROOT_DIR}/rdft/problem.c
        ${FFTW3_ROOT_DIR}/rdft/solve.c
        ${FFTW3_ROOT_DIR}/rdft/rank-geq2.c
        ${FFTW3_ROOT_DIR}/rdft/rank0-rdft2.c
        ${FFTW3_ROOT_DIR}/rdft/generic.c
        ${FFTW3_ROOT_DIR}/rdft/khc2hc.c
        ${FFTW3_ROOT_DIR}/rdft/rdft2-tensor-max-index.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/hc2c.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2c.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/hfb.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_14.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/codlist.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_128.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_11.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_13.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cb2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cb_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hc2cbdft_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/hb_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cb/r2cbIII_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2r/codlist.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2r/e10_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2r/e01_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_128.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/codlist.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_14.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_15.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_11.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_6.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_13.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_3.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_64.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_25.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf2_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_9.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft2_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf2_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_5.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_7.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_16.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_20.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_10.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cf_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cfII_2.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hc2cfdft_8.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_12.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/r2cf_32.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2cf/hf2_4.c
        ${FFTW3_ROOT_DIR}/rdft/scalar/r2r.c
        ${FFTW3_ROOT_DIR}/rdft/ct-hc2c.c
        ${FFTW3_ROOT_DIR}/rdft/kr2c.c
        ${FFTW3_ROOT_DIR}/rdft/rank-geq2-rdft2.c
        ${FFTW3_ROOT_DIR}/rdft/plan.c
        ${FFTW3_ROOT_DIR}/rdft/rdft2-strides.c
        ${FFTW3_ROOT_DIR}/rdft/direct2.c
        ${FFTW3_ROOT_DIR}/rdft/buffered.c
        ${FFTW3_ROOT_DIR}/rdft/dft-r2hc.c
        ${FFTW3_ROOT_DIR}/rdft/dht-r2hc.c
        ${FFTW3_ROOT_DIR}/rdft/direct-r2c.c
        ${FFTW3_ROOT_DIR}/rdft/rdft2-rdft.c
        ${FFTW3_ROOT_DIR}/rdft/rank0.c
        ${FFTW3_ROOT_DIR}/rdft/vrank-geq1.c
        ${FFTW3_ROOT_DIR}/rdft/vrank3-transpose.c
        ${FFTW3_ROOT_DIR}/rdft/solve2.c
        ${FFTW3_ROOT_DIR}/rdft/khc2c.c
        ${FFTW3_ROOT_DIR}/rdft/conf.c
        ${FFTW3_ROOT_DIR}/rdft/ct-hc2c-direct.c
        ${FFTW3_ROOT_DIR}/rdft/direct-r2r.c
        ${FFTW3_ROOT_DIR}/rdft/nop2.c
        ${FFTW3_ROOT_DIR}/rdft/hc2hc-generic.c
        ${FFTW3_ROOT_DIR}/rdft/vrank-geq1-rdft2.c
        ${FFTW3_ROOT_DIR}/rdft/hc2hc-direct.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/sse2/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/common/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/kcvi/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx512/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx-128-fma/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/neon/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/altivec/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2-128/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd128/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/generic-simd256/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/vsx/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx/hc2cbdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/codlist.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/genus.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_20.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_8.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_2.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_16.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_32.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_6.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cfdftv_12.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_10.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_4.c
#        ${FFTW3_ROOT_DIR}/rdft/simd/avx2/hc2cbdftv_8.c
        ${FFTW3_ROOT_DIR}/rdft/indirect.c
        ${FFTW3_ROOT_DIR}/rdft/nop.c
        )

    add_library(rtaudio STATIC ${RTAUDIO_SOURCES})
    add_library(fftw3api STATIC ${FFTW3_API_SOURCES})
add_library(fftw3kernel STATIC  ${FFTW3_KERNEL_SOURCES})
add_library(fftw3threads STATIC  ${FFTW3_THREADS_SOURCES})
add_library(fftw3reodft STATIC  ${FFTW3_REODFT_SOURCES})
add_library(fftw3dft STATIC  ${FFTW3_DFT_SOURCES})
add_library(fftw3rdft STATIC  ${FFTW3_RDFT_SOURCES})


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(TuneIt
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET TuneIt APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(TuneIt SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(TuneIt
          ${PROJECT_SOURCES}
        )
    endif()
endif()


target_include_directories(fftw3api PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)
target_include_directories(fftw3kernel PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)
target_include_directories(fftw3threads PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)
target_include_directories(fftw3reodft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)
target_include_directories(fftw3dft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)
target_include_directories(fftw3rdft PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/fftw3config)

target_link_libraries(TuneIt
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick
  fftw3api
  fftw3kernel
  fftw3threads
  fftw3reodft
  fftw3dft
  fftw3rdft
  rtaudio
)
set_target_properties(TuneIt PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

qt_add_qml_module(TuneIt
    URI com.bgcottrell.tuneit.qmlcomponents
    VERSION 1.0)

install(TARGETS TuneIt
    BUNDLE DESTINATION ${CMAKE_BINARY_DIR}
    LIBRARY DESTINATION ${CMAKE_BINARY_DIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_import_qml_plugins(TuneIt)
    qt_finalize_executable(TuneIt)
endif()
