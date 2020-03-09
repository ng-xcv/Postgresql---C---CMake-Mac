#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
    string sql;

    try {
        connection C("dbname = ng user = ng password = ng \
        hostaddr = 127.0.0.1 port = 5432");
        if (C.is_open()) {
            cout << "Opened database successfully: " << C.dbname() << endl;
        } else {
            cout << "Can't open database" << endl;
            return 1;
        }

        /* Create SQL statement */
        sql = "SELECT * FROM Batiment";

        /* Create a non-transactional object. */
        nontransaction N(C);

        /* Execute SQL query */
        result R( N.exec( sql ));

        /* List down all the records */
        for (result::const_iterator c = R.begin(); c != R.end(); ++c) {

            cout << "ID = " << c[0].as<int>() << endl;
            cout << "Numero = " << c[1].as<string>() << endl;
            cout << "Adresse = " << c[2].as<string>() << endl;
            cout << "Nom = " << c[3].as<string>() << endl;
            cout << "--------------------------------------" << endl;
        }
        cout << "Operation done successfully" << endl;
        C.disconnect ();
    } catch (const std::exception &e) {
        cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
