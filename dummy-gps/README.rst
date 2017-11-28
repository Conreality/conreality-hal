******************
Dummy GPS Receiver
******************

This is a simple dummy driver for simulating a stationary `GPS receiver
<https://en.wikipedia.org/wiki/GPS_navigation_device>`__.

Usage
=====

Usage Reference
---------------

::

   usage: dummy-gps [-i INTERVAL] [-n NOISE] [LAT] [LON]

Usage Example
-------------

Output GPS coordinates at 1.5-second intervals, with 1% noise, centered
around 60°08'43.4"N 24°59'17.3"E:

::

   usage: dummy-gps -i 1.5 -n 0.01 60.145400 24.988140
