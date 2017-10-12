    int compareVersion(string version1, string version2) {
        int v1_head = 0;
        int v1_tail = 0;
        
        int v2_head = 0;
        int v2_tail = 0;
        
        size_t index1 = 0;
        size_t index2 = 0;
        
        while((index1 < version1.size()) || (index2 < version2.size()))
        {
            
           for(; index1 < version1.size(); index1++)
            {
                if(version1[index1] != '.')
                    v1_head = v1_head * 10 + (version1[index1] - '0');
                else
                    break;
            }
            for(; index2 < version2.size(); index2++)
            {
                if(version2[index2] != '.')
                    v2_head = v2_head * 10 + (version2[index2] - '0');
                else
                    break;
            }
            
            

            if(v1_head > v2_head)
                return 1;
            if(v1_head < v2_head)
                return -1;
            
            v1_head = 0;
            v2_head = 0;

            index1++;
            index2++;
        }
        
       
        
        return 0;
        
        
        
        
        
        
    }



