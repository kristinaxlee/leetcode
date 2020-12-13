class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        # use hash map, store the number as the key and the index as the value
    
        numbers = {} # numbers[number] = index
        curIndex = 0
        answer = [-1, -1]
        
        while(True):
            
            # if we find the other number that adds up to target, return the answer
            if target-nums[curIndex] in numbers.keys():
                answer[1] = curIndex
                answer[0] = numbers[target - nums[curIndex]]
                break
            
            #else, put the current number in the dictionary
            else:
                numbers[nums[curIndex]] = curIndex
            
            curIndex +=1
        
        return answer
        