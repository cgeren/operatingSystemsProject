#pragma once

#include <openssl/rsa.h>
#include <string>

/// req_key() writes a request for the server's key on a socket descriptor.
/// When it gets a key back, it writes it to a file.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param keyfile The name of the file to which the key should be written
void req_key(int sd, const std::string &keyfile);

// NB: The remaining function declarations have the same signature, so that we
//     can store pointers to them in an array

/// req_reg() sends the REG command to register a new user
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
void req_reg(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &, const std::string &);

/// req_bye() writes a request for the server to exit.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
void req_bye(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &, const std::string &);

/// req_sav() writes a request for the server to save its contents
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
void req_sav(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &, const std::string &);

/// req_cpw() sends the CPW command to change the password of a user
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param newpass The new password
void req_cpw(int sd, EVP_PKEY *pubkey, const std::string &user, const std::string &pass,
             const std::string &newpass, const std::string &);

/// req_set() sends the SET command to set the content for a user
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param setfile The file whose contents should be sent
void req_set(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &setfile,
             const std::string &);

/// req_get() requests the content associated with a user, and saves it to a
/// file called <user>.file.dat.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param getname The name of the user whose content should be fetched
void req_get(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &getname,
             const std::string &);

/// req_all() sends the ALL command to get a listing of all users, formatted
/// as text with one entry per line.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param allfile The file where the result should go
void req_all(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &allfile,
             const std::string &);

/// req_kvi() sends the KVI command to set a key/value pair
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param key     The key to be set
/// @param valfile The file whose contents should be sent as the value
void req_kvi(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &key,
             const std::string &valfile);

/// req_kvu() sends the KVU command to upsert a key/value pair
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param key     The key to be set
/// @param valfile The file whose contents should be sent as the value
void req_kvu(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &key,
             const std::string &valfile);

/// req_kva() sends the KVA command to get a listing of all keys, formatted
/// as text with one entry per line.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param keyfile The file where the result should go
void req_kva(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &keyfile,
             const std::string &);

/// req_kvg() requests the value associated with a key, and saves it to a
/// file called <key>.file.dat.
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param key     The key whose value should be fetched
void req_kvg(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &key,
             const std::string &);

/// req_kvd() sends the KVD command to delete a key/value mapping
///
/// @param sd      The open socket descriptor for communicating with the server
/// @param pubkey  The public key of the server
/// @param user    The name of the user doing the request
/// @param pass    The password of the user doing the request
/// @param key     The key to be set
void req_kvd(int sd, EVP_PKEY *pubkey, const std::string &user,
             const std::string &pass, const std::string &key,
             const std::string &);
