// 牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
// 同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
// 例如，“student. a am I”。
// 后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
// Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？


class Solution {
public:
    string ReverseSentence(string str) {
        auto length = str.size();
        if(length == 0) return "";
         
        for (int i = 0, mark = 0; i < length; ++i) {
            if(i+1<length && str[i+1] == ' ' || i == length-1){
                ReverseWord(str, mark, i);
                mark = i + 2;
            }
        }
        ReverseWord(str, 0, length-1);
        return str;
    }
     
    void ReverseWord(string &str, int begin, int end){
        while(begin < end){
            swap(str[begin++],str[end--]);
        }
    }
};
