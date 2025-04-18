class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        std::vector<int> result(seq.size());
        int depth = 0;

        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                result[i] = depth % 2; 
                depth++;
            }else{ 
                depth--;
                result[i] = depth % 2; 
            }
        }
        return result;
    }
};
