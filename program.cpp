// Let Catch provide main():
#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "queue.h"

TEST_CASE( "Testing the insert call in the queue", "[single-file]" )
{
	QueueDataStructure q;

	REQUIRE( q.top() == nullptr );
	q.insert("home");

	NodeOfQueue* node = q.top();
	REQUIRE( node != nullptr );
	REQUIRE( node->data.compare("home") == 0 );

	//cleaning
	//delete node;
}

TEST_CASE( "Testing the insert and remove calls in the queue", "[single-file]" )
{
    SECTION( "Inserting" )
	{
		QueueDataStructure q;
		q.insert("home");
        q.insert("cat");
		NodeOfQueue* node = q.top();
		REQUIRE( node->data.compare("home") == 0 );
		node = q.remove();
		delete node;
		
		node = q.top();
		REQUIRE( node->data.compare("cat") == 0 );
		node = q.remove();
		delete node;
		
		REQUIRE( q.top() == nullptr );
    }
}

SCENARIO( "Teste the insert in the queue", "[single-file]" )
{
    GIVEN( "A queue with 3 elements" )
	{
        QueueDataStructure q;
		q.insert("home");
		q.insert("cat");
		q.insert("roof");

        WHEN( "A single entry is removed" )
		{
			NodeOfQueue* rem = q.remove();
			REQUIRE( rem->data.compare("home") ==0 );
			delete rem;

			THEN( "It should exist 2 other nodes" )
			{
				NodeOfQueue* top = nullptr;
				while (q.top() != nullptr)
				{
					top = q.remove();
					assert( top != nullptr);
					delete top;
				}
			}
		}
	}
}

SCENARIO( "Teste the insert and delete in the queue", "[single-file]" )
{
    GIVEN( "A queue " )
	{
        QueueDataStructure q;

        WHEN( "5 nodes are inserted" )
		{
            REQUIRE( q.insert("home") != nullptr );
			REQUIRE( q.insert("cat") != nullptr );
			REQUIRE( q.insert("roof") != nullptr );
			REQUIRE( q.insert("red") != nullptr );
			REQUIRE( q.insert("blue") != nullptr );

            THEN( "It should 5 nodes, in order" )
			{
				NodeOfQueue* node = nullptr;
				node = q.remove();
                
				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("home") ==0 );
				delete node;

				node = q.remove();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("cat") ==0 );
				delete node;

				node = q.remove();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("roof") ==0 );
				delete node;

				node = q.remove();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("red") ==0 );
				delete node;

				node = q.remove();

				REQUIRE( node != nullptr );
				REQUIRE( node->data.compare("blue") ==0 );
				delete node;
            }
        }
    }
}

