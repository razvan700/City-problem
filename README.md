# City-problem
A problem that was given as a test during one oop exams in university. The classes person and building, and the inheriting ones were used to print information about the people in a certain building. Also the average salaries were printed.
The output will consist of statistics about the settlement created using these buildings as follows:

Type: The type of settlement. This type can be "Village," "Town," or "Capital." To determine the type of settlement, the following conditions must be met:
Capital: CityHall >= 3, Hospital >= 2, PoliceStation >= 3, House >= 8, Block >= 4
City: CityHall >= 2, Hospital >= 1, PoliceStation >= 2, House >= 4, Block >= 1
Village: Anything other than the conditions mentioned above

Number of patients in hospitals: The total number of patients in all hospitals
Average salary for doctors: The average salary of all doctors in all hospitals
Average salary for cops: The average salary of all police officers in all police stations
Average salary for mayors: The average salary of all mayors in all city halls
Average salary for city hall employees: The average salary of all employees in all city halls
Average age of busted in police stations: The average age of all arrested individuals in all police stations

The following lines should be in the following format:
Number of people in House house_name: The number of people in that house, including the owner if there is one
Number of people in Block block_name: The number of people in that block, including the administrator if there is one

The above lines will be listed in the order in which the houses and blocks were provided from the input.
Administrators of house and block: The names of individuals who are both block administrators and house owners. If there is no such person, it will be indicated by the word "Nobody."
