#ifndef ADECODER_DUMMY_H
#define ADECODER_DUMMY_H

#include <cstdint>
#include <cstdlib>
#include <cstring>

// Dummy AudioDecoder struct
struct AudioDecoder {
    void* stream;
    int* outChannels;
    int* outSampleRate;
    int* outSize;
    unsigned int fakeCursor;
};

// Dummy Create_AudioDecoder
inline AudioDecoder* Create_AudioDecoder(
    unsigned int (*readFunc)(void* stream, void* buffer, unsigned int size),
    void* stream,
    int* outChannels,
    int* outSampleRate,
    int* outSize
) {
    // Allocate dummy
    AudioDecoder* decoder = (AudioDecoder*)malloc(sizeof(AudioDecoder));
    decoder->stream = stream;
    decoder->outChannels = outChannels;
    decoder->outSampleRate = outSampleRate;
    decoder->outSize = outSize;
    decoder->fakeCursor = 0;

    if (outChannels) *outChannels = 2;       // Stereo
    if (outSampleRate) *outSampleRate = 44100;
    if (outSize) *outSize = 100000;          // Arbitrary dummy size

    return decoder;
}

// Dummy AudioDecoder_Read: just returns dummy data (e.g., silence)
inline int AudioDecoder_Read(AudioDecoder* decoder, void* buffer, unsigned int size) {
    if (!decoder) return 0;

    unsigned char* buf = (unsigned char*)buffer;
    for (unsigned int i = 0; i < size; i++) {
        buf[i] = 0; // Silent PCM
    }

    decoder->fakeCursor += size;
    return size;
}

// Dummy AudioDecoder_Close
inline void AudioDecoder_Close(AudioDecoder* decoder) {
    free(decoder);
}

#endif // ADECODER_DUMMY_H
