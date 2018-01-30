#define CATCH_CONFIG_MAIN

#include "catch.hpp"

#include "njoy21.hpp"

using namespace njoy::njoy21::input;

SCENARIO( "CCCCR, Card1, Nbrks",
          "[CCCCR] [Card1] [Nbrks]" ){
  const int nisot = -22;
  const int nin = 23;
  GIVEN( "valid inputs" ){
    WHEN( "valid inputs are provided" ){
      for( auto i : {0, -20, -55, -99} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "the value can be verified" ){
          REQUIRE( i == argument::extract< CCCCR::Card1::Nbrks >(
                                                      iss, nisot, nin ).value );
        }
      }
    } // WHEN

    WHEN( "no value is provided" ){
      iRecordStream<char> iss( std::istringstream( " /" ) );

      THEN( "the default value can be verified" ){
        REQUIRE( 0 == argument::extract< CCCCR::Card1::Nbrks >(
                                                      iss, nisot, nin ).value );
      }
    } // WHEN
  } // GIVEN

  GIVEN( "invalid inputs" ){
    WHEN( "invalid inputs are provided" ){
      for( auto i : {-100, -23, -22, -19, -1, 1, 19, 20, 22, 23, 99, 100} ){
        iRecordStream<char> iss( std::istringstream( std::to_string( i ) ) );

        THEN( "an exception is thrown" ){
          REQUIRE_THROWS( argument::extract< CCCCR::Card1::Nbrks >( iss, nisot,
                                                                        nin ) );
        }
      }
    } // WHEN
  } // GIVEN
} // SCENARIO