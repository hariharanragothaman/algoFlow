/*
 *  We have a sequence of choices - they can be houses, numbers (or) days.
 *  For each position 'i', if we take it, we can't take its immediate neighbours.
 *  And we want to maximize the total gain
 */


/*
 *  DP[i] = maximum value containing the first 'i' items.
 *  Each item has the value of val[i]
 *
 *  DP[i] = max( DP[i-1], DP[i-2], + value[i] )
 *
 *  DP[i-1] : Skip Current Item
 *  DP[i-2] + value[i] = Take current item, but skip the previous one.
 *
 *  Base Cases -
 *  DP[0] = 0
 *  DP[1] = value[1]
 *
 *
 *   Imagine Houses with money - [2, 7, 9, 3, 1]
 *
 *   1          Take 2                  DP[1] = 2
 *   2          max(2, 7) = 7           DP[2] = 7
 *   3          max(7, 2 + 9)           DP[3] = 11
 *   4          max(11, 3+7)            DP[4] = 11
 *   5          max(11, 1+11)           DP[5] = 12
 */

/*
 *
 * Problem	Mapping
House Robber	Houses = array, can’t rob adjacent
Delete and Earn (Alex problem)	Numbers = “houses”, can’t take adjacent numbers
Maximum sum of non-adjacent elements	Same as House Robber
Paint House (with color constraints)	Extended version where adjacency means “same color”
Maximum points from tasks with cooldown	Cooldown creates the same dependency gap
Weighted interval scheduling	Sort by end times, choose dp[i-1] or dp[p[i]] + val[i] — generalization of House Robber

198. House Robber — the base template.
213. House Robber II — same, but array is circular → handle first/last separately.
337. House Robber III — houses on a tree → same idea with tree DP (take node ⇒ skip children).
740. Delete and Earn — compress counts to val[x] = x*cnt[x], then run House Robber on x.
309. Best Time to Buy and Sell Stock with Cooldown — “cooldown” acts like skip one day after taking; same spirit: taking blocks neighbors.
1235. Maximum Profit in Job Scheduling — generalization: sort jobs, dp[i] = max(dp[i-1], dp[p(i)] + profit[i]) where p(i) is last non-overlapping job.

Codeforces (perfect matches & close cousins)

455A – Boredom — exact same as Delete & Earn / House Robber on values.
607A – Chain Reaction — pick towers; destroying one removes a range around it → sort + “take or skip” with predecessor index (weighted scheduling flavor).
Edu DP – Task W (Intervals) — classic weighted interval scheduling (the generalized template).


How to map them (mental guide)
Line with adjacent ban → dp[i] = max(dp[i-1], dp[i-2] + val[i]).
Circular line → solve twice: [0..n-2] and [1..n-1], take max.
Tree → for each node: take = val + sum(skip children), skip = sum(max(take, skip) for children).
Value compression (Delete & Earn/Boredom) → build val[x]=x*cnt[x] then run House Robber over x.
Cooldown / gaps → “taking blocks next k items/days” → jump back to the nearest allowed state.
Intervals (jobs) → sort by end, binary search p(i): dp[i]=max(dp[i-1], dp[p(i)]+profit[i]).
 *
 */
