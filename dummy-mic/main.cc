/* This is free and unencumbered software released into the public domain. */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <conreality/ddk.h>

#include <opus.h>    /* for libopus */

#include <assert.h>  /* for assert() */
#include <chrono>    /* for std::chrono */
#include <cstdio>    /* for stderr, std::f*() */
#include <cstdlib>   /* for EXIT_*, std::atoi() */
#include <memory>    /* for std::unique_ptr */
#include <stdexcept> /* for std::runtime_error */
#include <system_error>
#include <thread>    /* for std::this_thread */
#include <unistd.h>  /* for getopt() */

static void
usage(const char* const program) {
  std::fprintf(stderr, "usage: %s [-c CHANNELS] [-s KHZ] [-b KBITS]\n", program);
}

int
main(int argc, char* const argv[]) {
  /* Define default parameters: */
  int channels{2};     // -c %d
  int sample_rate{48}; // -s %d
  int bit_rate{64};    // -b %d

  /* Parse command-line options: */
  const char* program = argv[0];
  {
    int c;
    while ((c = getopt(argc, argv, "c:b:s:?h")) != -1) {
      switch (c) {
        case 'c': channels = std::atoi(optarg); break;
        case 'b': bit_rate = std::atoi(optarg); break;
        case 's': sample_rate = std::atoi(optarg); break;
        case '?': case 'h': // fall through
        default: return usage(program), EXIT_SUCCESS;
      }
    }
    argc -= optind, argv += optind;
  }

  /* Validate command-line options: */
  if (sample_rate != 8 && sample_rate != 12 && sample_rate != 16 &&
      sample_rate != 24 && sample_rate != 48) {
    std::fprintf(stderr, "%s: %s\n", program, "invalid sample rate");
    return EXIT_FAILURE;
  }

  /* Parse command-line arguments: */
  if (argc != 1) return usage(program), EXIT_FAILURE;

  try {
    /* Open the driver input & output streams: */
    conreality::ddk::input in;
    conreality::ddk::output out;

    /* Open the specified input audio file: */
    std::unique_ptr<FILE, int(*)(FILE*)> input{fopen(argv[0], "re"), std::fclose};
    if (!input) {
      throw std::system_error{errno, std::system_category()};
    }

    std::unique_ptr<OpusEncoder, void(*)(OpusEncoder*)> encoder{nullptr, opus_encoder_destroy};

    int error;
    encoder.reset(opus_encoder_create(sample_rate * 1'000, channels, OPUS_APPLICATION_VOIP, &error));
    if (error < 0) {
      throw std::runtime_error{"opus_encoder_create failed"};
    }
    assert(encoder);

    if ((error = opus_encoder_ctl(encoder.get(), OPUS_SET_BITRATE(bit_rate * 1'000))) < 0) {
      throw std::runtime_error{"opus_encoder_ctl failed"};
    }

    // TODO

#if 0
    /* Generate sensor readings to the output stream: */
    while (in.is_open()) {
      std::this_thread::sleep_for(std::chrono::seconds{1}); // TODO
    }
#endif

    return EXIT_SUCCESS;
  }
  catch (const std::exception& error) {
    std::fprintf(stderr, "%s: %s\n", program, error.what());
    return EXIT_FAILURE;
  }
}
