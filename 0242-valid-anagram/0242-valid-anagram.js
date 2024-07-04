/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if(s.length !== t.length) {
        return false;
    }
    let char_s = s.split("");
    let char_t = t.split("");
    let arr_s = Array(26).fill(0);
    let arr_t = Array(26).fill(0);
    let count = 0;

    for(let i = 0; i < char_s.length; i++){
        arr_s[char_s[i].charCodeAt() - 'a'.charCodeAt()]++;
        arr_t[char_t[i].charCodeAt() - 'a'.charCodeAt()]++;
    }

    for(let i = 0; i < 26; i++) {
        count += Math.abs(arr_s[i] - arr_t[i]);
    }
    if (count !== 0)
    {
        return false;
    }
    return true;
};