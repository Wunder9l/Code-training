class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        if (strs.size == 0) {
            return "";
        }
        var common = strs.first().toList();
        for (i in 1 until strs.size) {
            if (strs[i].length < common.size) common = common.subList(0, strs[i].length);
            for (j in common.indices) {
                if (strs[i][j] != common[j]) {
                    common = common.subList(0, j);
                    break;
                }
            }
            if (0 == common.size) break;
        }
        return common.joinToString(separator="");
    }
}

