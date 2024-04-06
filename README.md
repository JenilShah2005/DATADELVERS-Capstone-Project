Team Data Delvers:
Ayush Dhamecha: 202301204
Rudra Raiyani: 202301223
Shah Jenil Smiteshbhai: 202301249
Vivek Dodiya: 202301250

Our Question:
P3. Entry Queue Manager:

You need to build an entry queue manager for a stadium. There are N entry gates.
As people keep coming in, they can line up in any of the queues or switch queues
anytime if they think that will get them a quicker entry. The entry queue manager
helps them in making that decision by suggesting:
(i) the waiting time for the last person in the queue to enter through any gate
(assume that it takes p mins for a single attendee to enter any gate),
(ii) the particular queue number(s) where one should be switching.
The queue manager must be designed to minimize the time for M people to enter
the stadium. Each gate has an initial random assignment of M/2 people (a gate
may not have anyone assigned).
Comments:
● Please look at the changes.
● “Initial random assignment of M/2 people”: Half of the total number of
attendees (i.e., the capacity of the stadium) are already assigned to each
of the gates randomly (may not be equally distributed).




Our Assumptions:
1. For People Entering from outside takes 0 min to enter a queue
2. The Time for switch from one gate to any other gate is constant user defined but exist with a practcal constraint that it is always less than p.
3. only last person of a queue can switch for individual switching
4. only 1 person can enter to queue at a time from outside for entering option.


The time complexity of our overall code is O(N^2+M).
since M is the capacity of the stadium is mostly very high than the number of gates therefore M can be greater than N^2 hence time complexity is O(N^2+M).


The code makes a array of size N and a vector that can have size N-1 
Therfore the space complexity of the overall code is O(N).


We are Using Array and vector for our code Since we are treating every person in the queue equally so we have choosen Array and Vector to make our code's time and space complexity less.


For example,if we have N gates we will make integer data type array with size N which means we use space of 4N bytes and each index will store the number of people in that gate respectively which than we can increase or decrease.
On the other hand we can think about deque or queue,in it we have to make N queues and also 1 member in that queue will be represented by integer data type which in the worst case if we have M members in one queue than total space will be MN bytes hence array will be more sutable for this case.