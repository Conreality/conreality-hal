******
To-Dos
******

* Implement the ``dummy-mic`` driver.
* Implement the ``dummy-camera`` driver.
* Implement the ``dummy-control`` driver.

configure.ac
============

* Add a dependency on Lua?

dummy-camera
============

* Research and select a streaming video codec (taking also into account
  hardware acceleration on our target platforms).

  * Next generation:

    * https://www.xda-developers.com/av1-future-video-codecs-google-hevc/

    * https://en.wikipedia.org/wiki/AOMedia_Video_1

    * https://en.wikipedia.org/wiki/Daala

  * Current generation:

    * https://en.wikipedia.org/wiki/VP9

    * https://en.wikipedia.org/wiki/X265

  * Previous generation:

    * https://en.wikipedia.org/wiki/VP8

    * https://en.wikipedia.org/wiki/X264

    * https://en.wikipedia.org/wiki/Theora
