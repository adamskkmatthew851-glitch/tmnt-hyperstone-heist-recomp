cmake_minimum_required(VERSION 3.16)
project(TMNTRecomp VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(RECOMP_ROOT "${CMAKE_SOURCE_DIR}/segagenesisrecomp-master")
set(RUNNER_ROOT "${RECOMP_ROOT}/runner")

list(APPEND CMAKE_PREFIX_PATH "${RUNNER_ROOT}/external/SDL2/SDL2-2.28.5/cmake")
find_package(SDL2 REQUIRED)

file(GLOB_RECURSE TMNT_GENERATED_SOURCES "${CMAKE_SOURCE_DIR}/generated/*.c" "${RECOMP_ROOT}/external/rbengine/src/*.c")

set(TMNT_SOURCES
    "${RUNNER_ROOT}/main.c"
    "${RUNNER_ROOT}/audio.c"
    "${RUNNER_ROOT}/chip_trace.c"
    "${RUNNER_ROOT}/cmd_server_stub.c"
    "${RUNNER_ROOT}/glue.c"
    "${RUNNER_ROOT}/fiber_compat.c"
    "${RUNNER_ROOT}/crash_report.c"
    "${RUNNER_ROOT}/input_script.c"
    "${RUNNER_ROOT}/gamepad.c"
    "${RUNNER_ROOT}/input_map.c"
    "${RUNNER_ROOT}/app_config.c"
    "${RUNNER_ROOT}/diagnostic_replay.c"
    "${RUNNER_ROOT}/replay_writer.c"
    "${RUNNER_ROOT}/engine_worker.c"
    "${RUNNER_ROOT}/local_states.c"
    "${RUNNER_ROOT}/rb_probe.c"
    "${RUNNER_ROOT}/rb_capture.c"
    "${RUNNER_ROOT}/rb_state.c"
    "${RUNNER_ROOT}/host_atomic_file.c"
    "${RUNNER_ROOT}/host_stream.c"
    "${RUNNER_ROOT}/host_wait.c"
    "${RUNNER_ROOT}/frame_snapshots.c"
    "${RUNNER_ROOT}/game_cycles.c"
    "${RUNNER_ROOT}/load_hold.c"
    "${RUNNER_ROOT}/overlay_draw.c"
    "${RUNNER_ROOT}/persist_writer.c"
    "${RUNNER_ROOT}/reverse_debug.c"
    "${RUNNER_ROOT}/runtime_evidence.c"
    "${RUNNER_ROOT}/sim_step.c"
    "${RUNNER_ROOT}/cosim.c"
    "${RUNNER_ROOT}/cosim_cycles.c"
    "${RUNNER_ROOT}/cosim_state.c"
    "${RUNNER_ROOT}/cosim_visible.c"
    "${RUNNER_ROOT}/audio/event_queue.c"
    "${RUNNER_ROOT}/audio/ym2612_ymfm.cpp"
    "${RUNNER_ROOT}/external/ymfm/src/ymfm_opn.cpp"
    "${RUNNER_ROOT}/external/ymfm/src/ymfm_ssg.cpp"
    "${RUNNER_ROOT}/external/ymfm/src/ymfm_adpcm.cpp"
    "${RUNNER_ROOT}/external/ymfm/src/ymfm_pcm.cpp"
    "${RUNNER_ROOT}/audio/sn76489.c"
    "${RUNNER_ROOT}/audio/mixer.c"
    "${RUNNER_ROOT}/audio/observability.c"
    "${RUNNER_ROOT}/audio/audio_shadow.c"
    "${RUNNER_ROOT}/audio/fm_shadow.cpp"
    "${RUNNER_ROOT}/video/color_lut.c"
    "${RUNNER_ROOT}/video/genesis_vdp.c"
    "${RUNNER_ROOT}/video/genesis_bus.c"
    "${RUNNER_ROOT}/video/genesis_machine.c"
    "${RUNNER_ROOT}/video/genesis_hd_gpu.c"
    "${RUNNER_ROOT}/video/genesis_raster_jobs.c"
    "${RUNNER_ROOT}/z80_recomp.c"
    "${RUNNER_ROOT}/external/superzazu/z80.c"
    "${RUNNER_ROOT}/m68k_interp.c"
    "${RECOMP_ROOT}/recompiler/src/m68k_decoder.c"
    "${RECOMP_ROOT}/recompiler/src/rom_parser.c"
    "${CMAKE_SOURCE_DIR}/game/tmnt_spec.c"
    "${CMAKE_SOURCE_DIR}/game/win_entry.c"
    ${TMNT_GENERATED_SOURCES}
)

add_executable(TMNTRecomp ${TMNT_SOURCES})

target_include_directories(TMNTRecomp PRIVATE
    "${CMAKE_SOURCE_DIR}/generated"
    "${RUNNER_ROOT}"
    "${RUNNER_ROOT}/include"
    "${RUNNER_ROOT}/external/ymfm/src"
    "${RUNNER_ROOT}/external/superzazu"
    "${RUNNER_ROOT}/external/clowncommon"
    "${RECOMP_ROOT}/external/rbengine/include"
    "${RECOMP_ROOT}/external/z80-recomp-core/include"
    "${RECOMP_ROOT}/external/rbengine"
    "${RUNNER_ROOT}/video"
    "${RECOMP_ROOT}/recompiler/src"
)

set(TMNT_LIBS SDL2::SDL2 ws2_32 comdlg32)
target_link_libraries(TMNTRecomp PRIVATE ${TMNT_LIBS})

target_compile_definitions(TMNTRecomp PRIVATE
    INCLUDE_GENERATED_CODE=1
    GENESIS_COSIM=1
    ENABLE_RECOMPILED_CODE=1
    OWN_BACKEND=1
    DEFAULT_DEBUG_PORT=4378
    GENESIS_GAME_VERSION="1.0.0"
    GENESIS_WIDESCREEN_32_9_LABEL="32:9"
)

add_custom_command(TARGET TMNTRecomp POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${RUNNER_ROOT}/external/SDL2/SDL2-2.28.5/lib/x64/SDL2.dll"
        "$<TARGET_FILE_DIR:TMNTRecomp>"
)
