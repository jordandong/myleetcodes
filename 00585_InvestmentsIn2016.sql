/*
Description

Write a query to print the sum of all total investment values in 2016 (TIV_2016), to a scale of 2 decimal places, for all policy holders who meet the following criteria:
1. Have the same TIV_2015 value as one or more other policyholders.
2. Are not located in the same city as another policyholder (i.e.: the (latitude, longitude) attribute pairs must be unique).

Input Format: The insurance table is described as follows:
| Column Name | Type          |
|-------------|---------------|
| PID         | INTEGER(11)   |
| TIV_2015    | NUMERIC(15,2) |
| TIV_2016    | NUMERIC(15,2) |
| LAT         | NUMERIC(5,2)  |
| LON         | NUMERIC(5,2)  |
where PID is the policyholder's policy ID, TIV_2015 is the total investment value in 2015, TIV_2016 is the total investment value in 2016, LAT is the latitude of the policy holder's city, and LON is the longitude of the policy holder's city.

Sample Input
| PID | TIV_2015 | TIV_2016 | LAT | LON |
|-----|----------|----------|-----|-----|
| 1   | 10       | 10       | 10  | 10  |
| 2   | 10       | 20       | 10  | 10  |
| 3   | 30       | 30       | 30  | 30  |
| 4   | 10       | 40       | 40  | 40  |
| 5   | 10       | 60       | 10  | 30  |

Sample Output
| TIV_2016 |
|----------|
| 100.00   |

Explanation
For the first insurance record with PID '1' in the table, the TIV_2016 should not be counted,
 because its location (LAT and LON attribute pair) is the same as the insurance with PID '2'. 

Thus for the same reason, the second insurance record with PID '2' should not be taken into account.

To continue, the third insurance record with PID '3' has a unique location. 
However, its TIV_2015 '30' is not the same as other policyholders in TIV_2015. 

So it should not be counted neither.


But the last two insurance meet all the criteria:
- One or more other policyholders have the same TIV_2015 value '10'.
- The location information is unique.

So the result should be the 100, which is the sum of the TIV_2016 value of the last two records.
*/

# Write your MySQL query statement below
