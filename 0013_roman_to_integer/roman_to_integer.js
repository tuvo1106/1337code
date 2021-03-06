/**
 * Time:    O(n)
 * Space:   O(1)
 * @param   {string} s
 * @return  {number}
 */
const romanToInt = s => {
  hash_map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  }
  let prev = 0
  return s.split("").reduceRight((sum, el) => {
    let curr = hash_map[el]
    sum += prev > curr ? -curr : curr
    prev = curr
    return sum
  }, 0)
}
