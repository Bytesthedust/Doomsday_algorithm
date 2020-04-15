# Doomsday_algorithm
This C program can calculate the doomsday of given year in the Gregorian Calender

John Conway's algorithm

1. Anchor day
Century     Anchor Day      Index
1800-99     Friday          5
1900-99     Wednesday       3
2000-99     Tuesday         2
2100-99     Sunday          0

2. Doomsday
(((year / 12) + (year % 12) + (year % 12) / 4) % 7 + anchor) % 7 = Doomsday
where 'year' is the last 2 two digits of the given year(ex. 1966 -> 66) and 'anchor' is the Index after determining the Anchor Day.


