#include <stdio.h>
#include <mysql.h>

int main() {
    MYSQL *conn = mysql_init(NULL);
    printf("c'est bon");
    if (!conn) {
        printf("Erreur d'initialisation MySQL\n");
        return 1;
    }
    printf("c'est fini");

    if (mysql_real_connect(conn, "localhost", "root", "", "elections_candidats", 3308, NULL, 0)) {
        printf("✅ Connexion réussie à elections_candidats !\n");
    } else {
        printf("❌ Erreur de connexion : %s\n", mysql_error(conn));
    }

    mysql_close(conn);
    printf("cool");
    return 0;
}
