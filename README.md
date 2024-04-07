Team Data Delvers: Ayush Dhamecha: 202301204 Rudra Raiyani: 202301223 Shah Jenil Smiteshbhai: 202301249 Vivek Dodiya: 202301250

Our Question: P3. Entry Queue Manager:

You need to build an entry queue manager for a stadium. There are N entry gates. As people keep coming in, they can line up in any of the queues or switch queues anytime if they think that will get them a quicker entry. The entry queue manager helps them in making that decision by suggesting: (i) the waiting time for the last person in the queue to enter through any gate (assume that it takes p mins for a single attendee to enter any gate), (ii) the particular queue number(s) where one should be switching. The queue manager must be designed to minimize the time for M people to enter the stadium. Each gate has an initial random assignment of M/2 people (a gate may not have anyone assigned). Comments: ● Please look at the changes. ● “Initial random assignment of M/2 people”: Half of the total number of attendees (i.e., the capacity of the stadium) are already assigned to each of the gates randomly (may not be equally distributed).

Our Assumptions:

For People Entering from outside takes 0 min to enter a queue
The Time for switch from one gate to any other gate is constant user defined but exist with a practcal constraint that it is always less than p.
only last person of a queue can switch for individual switching
only 1 person can enter to queue at a time from outside for entering option.
The time complexity of our overall code is O(N^2+M). since M is the capacity of the stadium is mostly very high than the number of gates therefore M can be greater than N^2 hence time complexity is O(N^2+M).

The code makes a array of size N and a vector that can have size N-1 Therfore the space complexity of the overall code is O(N).

We are Using Array and vector for our code Since we are treating every person in the queue equally so we have choosen Array and Vector to make our code's time and space complexity less.

For example,if we have N gates we will make integer data type array with size N which means we use space of 4N bytes and each index will store the number of people in that gate respectively which than we can increase or decrease. On the other hand we can think about deque or queue,in it we have to make N queues and also 1 member in that queue will be represented by integer data type which in the worst case if we have M members in one queue than total space will be MN bytes hence array will be more sutable for this case.

Our final Complete Code file has name Capstone_P3.cpp

Minimize_for_M_people_algorithm.txt is pseudo code file for the third option minimize.

Switch_Queue.txt is pseudo code file for the 1st option Switch from a Queue.

Enter_A_Queue.txt is pseudo code file for 2nd option Enter to a Queue.

The time for the last person in a queue to enter is P*number of people in that queue.

Minimize_for_M.cpp is code file for the function to minizime entry.

Switch_Queue.cpp is the code file for the function to switch from a queue.

After integreating all the individuals functions all the editing in whole code and indiviual function has only be done in the integrated code.

The link give below is of our small demonstration on our capstone Project OutPut: https://drive.google.com/file/d/1X2VBZM8XXSwvzoQawYixtfloEsI-0Xty/view?usp=sharing

All the folders named Output and a number are screenshot of our output codes.

Contribution Table:
Approx contribution of each team member:
Ayush Dhamecha: 202301204           - 23% 
Rudra Raiyani: 202301223            - 22%
Shah Jenil Smiteshbhai: 202301249   - 31%
Vivek Dodiya: 202301250             - 24% 
