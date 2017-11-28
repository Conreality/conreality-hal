*************
Dummy IPS Tag
*************

This is a simple dummy driver for simulating a stationary `IPS tag
<https://en.wikipedia.org/wiki/Indoor_positioning_system>`__.

Usage
=====

Usage Reference
---------------

::

   usage: dummy-tag [-i PERIOD] [-n NOISE] [X] [Y] [Z]

Usage Example
-------------

Output IPS coordinates at 1.5-second intervals, with 1% noise, centered
around the local coordinate system point X=1m, Y=2m, Z=3m.

::

   usage: dummy-tag -i 1.5 -n 0.01 1.0 2.0 3.0
