# Computer Science Capstone

# [Professional Self-Assessment goes here]

## Code Review
This code review walks through the functionality of the original application, analyzes areas for improvement, and discusses the three enhancements that will be made to demonstrate my skills. Please visit [this link](https://youtu.be/DqEWDQfDiOk) to watch my code review.

You can view the original code for the Corner Grocer application [here](https://github.com/annajessing/annajessing.github.io/blob/main/Original%20Artifact.zip).

## Final Product
## Enhancement 1: Software Design & Engineering
#### Overview:
I chose to include this artifact in my portfolio because I can demonstrate growth in my skills and abilities in software development. Looking back on this program that I developed early in the SNHU Computer Science program, I found many opportunities for improvement. Therefore, in this enhancement I am demonstrating my ability to create a more robust program that follows coding best practices by incorporating additional input validation, error handling, and eliminating many hardcoded values to make future updates as seamless as possible. 

While I am making these improvements to the code itself, the primary enhancement to this program is translating it from C++ into Python. Through this translation, I am showcasing my coding skills in multiple programming languages. Additionally, when put together with my enhancements in the data structures and algorithms and databases categories, which will involve storing produce purchase history information in a database instead of a text file, I will demonstrate my ability to create a cohesive and fully functional software application designed for long-term use. 

#### For a more detailed narrative describing the enhancement process, challenges I faced, and what I learned, please visit this link.

## Enhancement 2: Algorithms & Data Structures
##### Overview:
I chose to include this artifact in my portfolio because I can demonstrate growth in my skills and abilities in algorithms and data structures. After all three enhancements are complete, the final application will use a non-relational database instead of reading data from a text file. As a result of this modification, new data structures must be created to effectively and efficiently access and loop through the Corner Grocer's sales data, creating the perfect opportunity for me to showcase my skills and abilities in algorithms and data structures.  

Within Corner Grocer’s sales database, the produce purchase history data is stored within a collection made up of documents with a key-value structure. This data structure is an appropriate choice because this application will be using MongoDB, which has a non-relational structure that provides flexibility and scalability. Additionally, MongoDB stores data internally in a binary JSON (BSON) format, so using JSON to represent the data being input and retrieved from the database allows the MongoDB driver to easily convert back and forth between JSON and BSON (MongoDB Inc., n.d.b).   

To streamline database interaction, I created a database class to manage database connections and define database queries. This class contains a query that reads data from the database into a cursor and passes it back to the main code. If the query returns a single item, the application logic accesses the fields containing the item name and the number of items purchased and prints out these values. If the query returns all items in the collection, the application logic iteratively accesses cursor contents, accessing the fields containing the item name and the number of items purchased and prints these values. I chose a cursor as the appropriate data structure to optimize querying, improve time complexity and efficiency, and improve overall performance; a cursor is more efficient for larger, non-relational datasets and uses less memory, so it optimizes the resources available and avoids a single, long wait time (MongoDB Inc., n.d.a). This enhancement showcases my understanding of the data structures required for application logic to work with documents stored in a non-relational database in an optimized and efficient way. When put together with my enhancements in the software design and engineering and databases categories, I will demonstrate my ability to create a cohesive and fully functional software application designed for long-term use. 

##### For a more detailed narrative describing the enhancement process, challenges I faced, and what I learned, please visit this link.


## Enhancement 3: Databases
##### Overview:
I chose to include this artifact in my portfolio because a real-world version of this application would use a database. Using a file to store purchase history data indicates that the current process of recording and/or obtaining this data is inefficient. Whether users are manually hand-jamming purchase history data into this file as customers make purchases or if they are downloading a copy of the data from a second storage location, neither of these methods are efficient for a business because they involve unnecessary manual steps. Storing purchase history data in a database is a better long-term solution for this application for many reasons. First, it will ensure that there is a single source of truth. Storing large amounts of ever-changing data in a file gets messy because there could be multiple versions of a file, making it difficult to identify which file has the most up-to-date data. Second, using a database is a more secure method of data storage; it is hard to ensure the security of a file because it is very easy to create copies and send them to anybody. Third, using a database will allow for scalability in the future. Databases are easy to scale up because they can handle large amounts of data without huge impacts to performance, whereas a file containing purchase history information for a business would very quickly have negative impacts to performance and overwhelm users. For all these reasons, this Python program will be greatly improved by connecting directly to a database storing purchase history information. 

##### For a more detailed narrative describing the enhancement process, challenges I faced, and what I learned, please visit this link.
