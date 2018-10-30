/*
 * rsa_encrypt.h
 *
 *  Created on: 2013-7-16
 *      Author: zhouzhijie
 */

#ifndef RSA_ENCRYPT_H_
#define RSA_ENCRYPT_H_
#ifdef __cplusplus
extern "C" {
#endif
    
enum
{
    CRYPT_OK = 0,
    CRYPT_ERR_INVALID_KEY_N = 1,
    CRYPT_ERR_INVALID_KEY_E = 2,
    CRYPT_ERR_ENCRYPT_WITH_RSA_PUBKEY = 3,
    CRYPT_ERR_DECRYPT_WITH_RSA_PRIVKEY = 4,
    CRYPT_ERR_NO_MEMORY = 5,
    CRYPT_ERR_ENCRYPT_WITH_DES_KEY = 6,
    CRYPT_ERR_DECRYPT_WITH_DES_KEY = 7,
    CRYPT_ERR_INVALID_PARAM = 8,
    CRYPT_ERR_LOAD_RSA_PRIVATE_KEY = 9,
};
    
int rsa_public_encrypt(const unsigned char* pInput, unsigned int uiInputLen
		, unsigned char** ppOutput, unsigned int* uiOutputLen
		, const char* pPublicKeyN, const char* pPublicKeyE);

int rsa_public_decrypt(const unsigned char* pInput, unsigned int uiInputLen
		, unsigned char** ppOutput, unsigned int* uiOutputLen
		, const char* pPublicKeyN, const char* pPublicKeyE);

int rsa_public_encrypt_pemkey(const unsigned char* pInput, unsigned int uiInputLen
        , unsigned char** ppOutput, unsigned int* uiOutputLen
        , const char* pPemPubKey, unsigned int pemPubKeyLen);
    
int rsa_public_decrypt_pemkey(const unsigned char* pInput, unsigned int uiInputLen
        , unsigned char** ppOutput, unsigned int* uiOutputLen
        , const char* pPemPubKey, unsigned int pemPubKeyLen);
    

int rsa_private_decrypt_pemkey(const unsigned char* pInput, unsigned int uiInputLen
        , unsigned char** ppOutput, unsigned int* uiOutputLen
        , const char* pPemPriKey, unsigned int pemPriKeyLen);

void GetSaltString(char* pOutString, int bytes = 32);
void* rsa_open_public_mem2(const char* pPublicKey);
void rsa_close(void* pRSA);
int rsa_public_encrypt2(void* pRSA, const unsigned char* fdata, int flen, unsigned char** pToData);

#ifndef Z_DEFAULT_COMPRESSION
#define Z_DEFAULT_COMPRESSION -1
#endif // !Z_DEFAULT_COMPRESSION

#ifndef Z_OK
#define Z_OK            0
#endif // !Z_OK

int ZipData(const unsigned char *source, unsigned long nSourceSize, unsigned char *dest, unsigned long* pDestSize, int level = Z_DEFAULT_COMPRESSION, int gzip = 0);
int GZipData(const unsigned char *source, unsigned long nSourceSize, unsigned char *dest, unsigned long* pDestSize, int level = Z_DEFAULT_COMPRESSION);
int UnZipData(const unsigned char *source, unsigned long nSourceSize, unsigned char *dest, unsigned long* pDestSize, int gzip = 0);
int UnGZipData(const unsigned char *source, unsigned long nSourceSize, unsigned char *dest, unsigned long* pDestSize);

#ifdef __cplusplus
}
#endif

#endif /* RSA_ENCRYPT_H_ */
