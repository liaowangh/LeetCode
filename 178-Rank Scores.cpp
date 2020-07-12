# Write your MySQL query statement below
SELECT s1.Score Score, COUNT(DISTINCT s2.Score) Rank
FROM Scores s1 JOIN Scores s2 ON s1.Score <= s2.Score
GROUP BY s1.Id, s1.Score
ORDER BY s1.Score DESC
