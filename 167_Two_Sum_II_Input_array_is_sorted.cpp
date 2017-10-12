    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> solution;

        auto first=numbers.begin();

        auto last=numbers.end()-1;

        while(first<last)

        {

            if((*first+*last)<target)

            {

                first++;

            }

            if((*first+*last)>target)

            {

               last--;

            }

            if((*first+*last)==target)

            {

                solution.push_back(first-numbers.begin()+1);

                solution.push_back(last-numbers.begin()+1);

                return solution;

            }

        }

       

                

        

    }
