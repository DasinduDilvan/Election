gcc -Isrc/admin -Isrc/party -Isrc/voter -Isrc/candidate \
src/main/main.c \
src/admin/admin_login.c \
src/party/party_login.c \
src/party/party_registration.c \
src/voter/voter_login.c \
src/voter/voter_registration.c \
src/candidate/candidate_login.c \
src/candidate/candidate_registration.c \
-o build/Election.exe
