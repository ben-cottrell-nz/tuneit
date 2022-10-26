
set(OBOE_SOURCES
    ${OBOE_DIR}/src/common/FilterAudioStream.cpp
    ${OBOE_DIR}/src/common/AudioStream.cpp
    ${OBOE_DIR}/src/common/AudioStreamBuilder.cpp
    ${OBOE_DIR}/src/common/FixedBlockAdapter.cpp
    ${OBOE_DIR}/src/common/SourceI32Caller.cpp
    ${OBOE_DIR}/src/common/SourceI16Caller.cpp
    ${OBOE_DIR}/src/common/QuirksManager.cpp
    ${OBOE_DIR}/src/common/OboeExtensions.cpp
    ${OBOE_DIR}/src/common/LatencyTuner.cpp
    ${OBOE_DIR}/src/common/StabilizedCallback.cpp
    ${OBOE_DIR}/src/common/Version.cpp
    ${OBOE_DIR}/src/common/Trace.cpp
    ${OBOE_DIR}/src/common/SourceI24Caller.cpp
    ${OBOE_DIR}/src/common/SourceFloatCaller.cpp
    ${OBOE_DIR}/src/common/Utilities.cpp
    ${OBOE_DIR}/src/common/DataConversionFlowGraph.cpp
    ${OBOE_DIR}/src/common/AudioSourceCaller.cpp
    ${OBOE_DIR}/src/common/FixedBlockReader.cpp
    ${OBOE_DIR}/src/common/FixedBlockWriter.cpp
    ${OBOE_DIR}/src/flowgraph/ChannelCountConverter.cpp
    ${OBOE_DIR}/src/flowgraph/MonoToMultiConverter.cpp
    ${OBOE_DIR}/src/flowgraph/MultiToManyConverter.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/PolyphaseResampler.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/MultiChannelResampler.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/PolyphaseResamplerMono.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/IntegerRatio.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/PolyphaseResamplerStereo.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/LinearResampler.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/SincResampler.cpp
    ${OBOE_DIR}/src/flowgraph/resampler/SincResamplerStereo.cpp
    ${OBOE_DIR}/src/flowgraph/FlowGraphNode.cpp
    ${OBOE_DIR}/src/flowgraph/SampleRateConverter.cpp
    ${OBOE_DIR}/src/flowgraph/SinkFloat.cpp
    ${OBOE_DIR}/src/flowgraph/SourceFloat.cpp
    ${OBOE_DIR}/src/flowgraph/ManyToMultiConverter.cpp
    ${OBOE_DIR}/src/flowgraph/MultiToMonoConverter.cpp
    ${OBOE_DIR}/src/flowgraph/ClipToRange.cpp
    ${OBOE_DIR}/src/flowgraph/MonoBlend.cpp
    ${OBOE_DIR}/src/flowgraph/SinkI32.cpp
    ${OBOE_DIR}/src/flowgraph/SinkI24.cpp
    ${OBOE_DIR}/src/flowgraph/RampLinear.cpp
    ${OBOE_DIR}/src/flowgraph/SinkI16.cpp
    ${OBOE_DIR}/src/flowgraph/SourceI24.cpp
    ${OBOE_DIR}/src/flowgraph/SourceI16.cpp
    ${OBOE_DIR}/src/flowgraph/SourceI32.cpp
    ${OBOE_DIR}/src/aaudio/AudioStreamAAudio.cpp
    ${OBOE_DIR}/src/aaudio/AAudioLoader.cpp
    ${OBOE_DIR}/src/fifo/FifoControllerIndirect.cpp
    ${OBOE_DIR}/src/fifo/FifoBuffer.cpp
    ${OBOE_DIR}/src/fifo/FifoController.cpp
    ${OBOE_DIR}/src/fifo/FifoControllerBase.cpp
    ${OBOE_DIR}/src/opensles/AudioOutputStreamOpenSLES.cpp
    ${OBOE_DIR}/src/opensles/AudioStreamOpenSLES.cpp
    ${OBOE_DIR}/src/opensles/OpenSLESUtilities.cpp
    ${OBOE_DIR}/src/opensles/EngineOpenSLES.cpp
    ${OBOE_DIR}/src/opensles/AudioInputStreamOpenSLES.cpp
    ${OBOE_DIR}/src/opensles/AudioStreamBuffered.cpp
    ${OBOE_DIR}/src/opensles/OutputMixerOpenSLES.cpp
)
add_library(oboe ${OBOE_SOURCES})
target_include_directories(oboe
        PRIVATE ${OBOE_DIR}/src
        PUBLIC ${OBOE_DIR}/include)
target_compile_options(oboe
        PRIVATE
        -std=c++17
        -Wall
        -Wextra-semi
        -Wshadow
        -Wshadow-field
        -Ofast
        "$<$<CONFIG:DEBUG>:-Werror>")
target_link_libraries(oboe PRIVATE log OpenSLES)