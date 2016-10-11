/*
Write a SQL query to find all numbers that appear at least three times consecutively.
+----+-----+
| Id | Num |
+----+-----+
| 1  |  1  |
| 2  |  1  |
| 3  |  1  |
| 4  |  2  |
| 5  |  1  |
| 6  |  2  |
| 7  |  2  |
+----+-----+
For example, given the above Logs table, 1 is the only number that appears consecutively for at least three times.
*/

# Write your MySQL query statement below
/*
SELECT DISTINCT Num AS ConsecutiveNums
FROM
(
    SELECT Num, 
           (
            CASE WHEN @prev <> (@prev := Num) THEN @consecutive_cnt := 1
                 ELSE @consecutive_cnt :=  @consecutive_cnt + 1
            END
           ) AS consecutive_cnt
    FROM Logs,
         (
          SELECT @consecutive_cnt := 0, 
                 @prev := (SELECT Num FROM Logs LIMIT 1)
         ) AS init
) AS t
WHERE consecutive_cnt = 3;
*/

SELECT DISTINCT t1.Num AS ConsecutiveNums
FROM Logs t1, Logs t2, Logs t3
WHERE t1.Id = t2.Id - 1 AND t2.Id = t3.Id -1
      AND t1.Num = t2.Num AND t2.Num = t3.Num
