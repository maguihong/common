#include"Type.h"
#include<stddef.h> // NULL
#include<string.h> // strxxx memxxx
#include<stdlib.h> // free malloc
#include<stdio.h> // snprintf
#include<time.h> // time_t time localtime

Status C8_Init(C8 *c8, const C* string, U8 size){
    if(c8 == NULL){
        return FAILURE;
    }

    if(c8->Buffer != NULL){
        free(c8->Buffer);
        c8->Buffer = NULL;
    }
    c8->Size = 0;

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
        length = (length < Max_U8 ? length : Max_U8 - 1);
        size = (size > length ? size : length + 1);
    }

    if((c8->Buffer = (C*) malloc(sizeof(C) * size)) != NULL){
        c8->Size = size;
        if(length > 0){
            memcpy(c8->Buffer, string, length);
        }
        c8->Buffer[length] = '\0';
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status C16_Init(C16 *c16, const C* string, U16 size){
    if(c16 == NULL){
        return FAILURE;
    }

    if(c16->Buffer != NULL){
        free(c16->Buffer);
        c16->Buffer = NULL;
    }
    c16->Size = 0;

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
        length = (length < Max_U16 ? length : Max_U16 - 1);
        size = (size > length ? size : length + 1);
    }

    if((c16->Buffer = (C*) malloc(sizeof(C) * size)) != NULL){
        c16->Size = size;
        if(length > 0){
            memcpy(c16->Buffer, string, length);
        }
        c16->Buffer[length] = '\0';
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status C32_Init(C32 *c32, const C* string, U32 size){
    if(c32 == NULL){
        return FAILURE;
    }

    if(c32->Buffer != NULL){
        free(c32->Buffer);
        c32->Buffer = NULL;
    }
    c32->Size = 0;

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
        length = (length < Max_U32 ? length : Max_U32 - 1);
        size = (size > length ? size : length + 1);
    }

    if((c32->Buffer = (C*) malloc(sizeof(C) * size)) != NULL){
        c32->Size = size;
        if(length > 0){
            memcpy(c32->Buffer, string, length);
        }
        c32->Buffer[length] = '\0';
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status C64_Init(C64 *c64, const C* string, U64 size){
    if(c64 == NULL){
        return FAILURE;
    }

    if(c64->Buffer != NULL){
        free(c64->Buffer);
        c64->Buffer = NULL;
    }
    c64->Size = 0;

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
        length = (length < Max_U64 ? length : Max_U64 - 1);
        size = (size > length ? size : length + 1);
    }

    if((c64->Buffer = (C*) malloc(sizeof(C) * size)) != NULL){
        c64->Size = size;
        if(length > 0){
            memcpy(c64->Buffer, string, length);
        }
        c64->Buffer[length] = '\0';
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status CT_Init(CT *ct, const C* string, UT size){
    if(ct == NULL){
        return FAILURE;
    }

    if(ct->Buffer != NULL){
        free(ct->Buffer);
        ct->Buffer = NULL;
    }
    ct->Size = 0;

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
        length = (length < Max_UT ? length : Max_UT - 1);
        size = (size > length ? size : length + 1);
    }

    if((ct->Buffer = (C*) malloc(sizeof(C) * size)) != NULL){
        ct->Size = size;
        if(length > 0){
            memcpy(ct->Buffer, string, length);
        }
        ct->Buffer[length] = '\0';
    }else{
        return FAILURE;
    }

    return SUCCESS;
}



Status C8_Set(C8 *c8, const C* string){
    if(c8 == NULL){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        c8->Buffer[0] = '\0';
    }else if(length < c8->Size){
        strcpy(c8->Buffer, string);
    }else{
        length = c8->Size - 1;
        memcpy(c8->Buffer, string, length);
        c8->Buffer[c8->Size] = '\0';
        return FAILURE;
    }

    return SUCCESS;
}

Status C16_Set(C16 *c16, const C* string){
    if(c16 == NULL){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        c16->Buffer[0] = '\0';
    }else if(length < c16->Size){
        strcpy(c16->Buffer, string);
    }else{
        length = c16->Size - 1;
        memcpy(c16->Buffer, string, length);
        c16->Buffer[c16->Size] = '\0';
        return FAILURE;
    }

    return SUCCESS;
}

Status C32_Set(C32 *c32, const C* string){
    if(c32 == NULL){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        c32->Buffer[0] = '\0';
    }else if(length < c32->Size){
        strcpy(c32->Buffer, string);
    }else{
        length = c32->Size - 1;
        memcpy(c32->Buffer, string, length);
        c32->Buffer[c32->Size] = '\0';
        return FAILURE;
    }

    return SUCCESS;
}

Status C64_Set(C64 *c64, const C* string){
    if(c64 == NULL){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        c64->Buffer[0] = '\0';
    }else if(length < c64->Size){
        strcpy(c64->Buffer, string);
    }else{
        length = c64->Size - 1;
        memcpy(c64->Buffer, string, length);
        c64->Buffer[c64->Size] = '\0';
        return FAILURE;
    }

    return SUCCESS;
}

Status CT_Set(CT *ct, const C* string){
    if(ct == NULL){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        ct->Buffer[0] = '\0';
    }else if(length < ct->Size){
        strcpy(ct->Buffer, string);
    }else{
        length = ct->Size - 1;
        memcpy(ct->Buffer, string, length);
        ct->Buffer[ct->Size] = '\0';
        return FAILURE;
    }

    return SUCCESS;
}



Status C8_Cat(C8 *c8, const C* string){
    ST available = 0;
    if(c8 == NULL || (available = (c8->Size - strlen(c8->Buffer) - 1)) <= 0){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        return FAILURE;
    }else if(length > 0 && length <= available){
        strcat(c8->Buffer, string);
        return SUCCESS;
    }else{
        strncat(c8->Buffer, string, available);
        return FAILURE;
    }
}

Status C16_Cat(C16 *c16, const C* string){
    ST available = 0;
    if(c16 == NULL || (available = (c16->Size - strlen(c16->Buffer) - 1)) <= 0){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        return FAILURE;
    }else if(length > 0 && length <= available){
        strcat(c16->Buffer, string);
        return SUCCESS;
    }else{
        strncat(c16->Buffer, string, available);
        return FAILURE;
    }
}

Status C32_Cat(C32 *c32, const C* string){
    ST available = 0;
    if(c32 == NULL || (available = (c32->Size - strlen(c32->Buffer) - 1)) <= 0){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        return FAILURE;
    }else if(length > 0 && length <= available){
        strcat(c32->Buffer, string);
        return SUCCESS;
    }else{
        strncat(c32->Buffer, string, available);
        return FAILURE;
    }
}

Status C64_Cat(C64 *c64, const C* string){
    ST available = 0;
    if(c64 == NULL || (available = (c64->Size - strlen(c64->Buffer) - 1)) <= 0){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        return FAILURE;
    }else if(length > 0 && length <= available){
        strcat(c64->Buffer, string);
        return SUCCESS;
    }else{
        strncat(c64->Buffer, string, available);
        return FAILURE;
    }
}

Status CT_Cat(CT *ct, const C* string){
    ST available = 0;
    if(ct == NULL || (available = (ct->Size - strlen(ct->Buffer) - 1)) <= 0){
        return FAILURE;
    }

    UX length = 0;
    if(string != NULL){
        length = strlen(string);
    }

    if(length == 0){
        return FAILURE;
    }else if(length > 0 && length <= available){
        strcat(ct->Buffer, string);
        return SUCCESS;
    }else{
        strncat(ct->Buffer, string, available);
        return FAILURE;
    }
}



Status C8_Del(C8 *c8){
    if(c8 == NULL){
        return FAILURE;
    }

    if(c8->Buffer != NULL){
        free(c8->Buffer);
        c8->Buffer = NULL;
    }
    c8->Size = 0;

    return SUCCESS;
}

Status C16_Del(C16 *c16){
    if(c16 == NULL){
        return FAILURE;
    }

    if(c16->Buffer != NULL){
        free(c16->Buffer);
        c16->Buffer = NULL;
    }
    c16->Size = 0;

    return SUCCESS;
}

Status C32_Del(C32 *c32){
    if(c32 == NULL){
        return FAILURE;
    }

    if(c32->Buffer != NULL){
        free(c32->Buffer);
        c32->Buffer = NULL;
    }
    c32->Size = 0;

    return SUCCESS;
}

Status C64_Del(C64 *c64){
    if(c64 == NULL){
        return FAILURE;
    }

    if(c64->Buffer != NULL){
        free(c64->Buffer);
        c64->Buffer = NULL;
    }
    c64->Size = 0;

    return SUCCESS;
}

Status CT_Del(CT *ct){
    if(ct == NULL){
        return FAILURE;
    }

    if(ct->Buffer != NULL){
        free(ct->Buffer);
        ct->Buffer = NULL;
    }
    ct->Size = 0;

    return SUCCESS;
}



Status B8_Init(B8 *b8, const B* bytes, U8 size){
    if(b8 == NULL){
        return FAILURE;
    }

    if(b8->Buffer != NULL){
        free(b8->Buffer);
        b8->Buffer = NULL;
    }
    b8->Size = 0;
    b8->Length = 0;

    UX length = 0;
    if(bytes != NULL){
        length = strlen(bytes) + 1;
        length = (length <= Max_U8 ? length : Max_U8);
        size = (size >= length ? size : length);
    }

    if((b8->Buffer = (B*) malloc(sizeof(B) * size)) != NULL){
        b8->Size = size;
        if(length > 0){
            memcpy(b8->Buffer, bytes, length);
        }
        b8->Length = length;
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status B16_Init(B16 *b16, const B* bytes, U16 size){
    if(b16 == NULL){
        return FAILURE;
    }

    if(b16->Buffer != NULL){
        free(b16->Buffer);
        b16->Buffer = NULL;
    }
    b16->Size = 0;
    b16->Length = 0;

    UX length = 0;
    if(bytes != NULL){
        length = strlen(bytes) + 1;
        length = (length <= Max_U16 ? length : Max_U16);
        size = (size >= length ? size : length);
    }

    if((b16->Buffer = (B*) malloc(sizeof(B) * size)) != NULL){
        b16->Size = size;
        if(length > 0){
            memcpy(b16->Buffer, bytes, length);
        }
        b16->Length = length;
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status B32_Init(B32 *b32, const B* bytes, U32 size){
    if(b32 == NULL){
        return FAILURE;
    }

    if(b32->Buffer != NULL){
        free(b32->Buffer);
        b32->Buffer = NULL;
    }
    b32->Size = 0;
    b32->Length = 0;

    UX length = 0;
    if(bytes != NULL){
        length = strlen(bytes) + 1;
        length = (length <= Max_U32 ? length : Max_U32);
        size = (size >= length ? size : length);
    }

    if((b32->Buffer = (B*) malloc(sizeof(B) * size)) != NULL){
        b32->Size = size;
        if(length > 0){
            memcpy(b32->Buffer, bytes, length);
        }
        b32->Length = length;
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status B64_Init(B64 *b64, const B* bytes, U64 size){
    if(b64 == NULL){
        return FAILURE;
    }

    if(b64->Buffer != NULL){
        free(b64->Buffer);
        b64->Buffer = NULL;
    }
    b64->Size = 0;
    b64->Length = 0;

    UX length = 0;
    if(bytes != NULL){
        length = strlen(bytes) + 1;
        length = (length <= Max_U64 ? length : Max_U64);
        size = (size >= length ? size : length);
    }

    if((b64->Buffer = (B*) malloc(sizeof(B) * size)) != NULL){
        b64->Size = size;
        if(length > 0){
            memcpy(b64->Buffer, bytes, length);
        }
        b64->Length = length;
    }else{
        return FAILURE;
    }

    return SUCCESS;
}

Status BT_Init(BT *bt, const B* bytes, UT size){
    if(bt == NULL){
        return FAILURE;
    }

    if(bt->Buffer != NULL){
        free(bt->Buffer);
        bt->Buffer = NULL;
    }
    bt->Size = 0;
    bt->Length = 0;

    UX length = 0;
    if(bytes != NULL){
        length = strlen(bytes) + 1;
        length = (length <= Max_UT ? length : Max_UT);
        size = (size >= length ? size : length);
    }

    if((bt->Buffer = (B*) malloc(sizeof(B) * size)) != NULL){
        bt->Size = size;
        if(length > 0){
            memcpy(bt->Buffer, bytes, length);
        }
        bt->Length = length;
    }else{
        return FAILURE;
    }

    return SUCCESS;
}



Status B8_Set(B8 *b8, const B* bytes, U8 length){
    if(b8 == NULL){
        return FAILURE;
    }

    if(length == 0 || bytes == NULL){
        b8->Length = 0;
    }else if(length <= b8->Size){
        memcpy(b8->Buffer, bytes, length);
    }else{
        length = b8->Size;
        memcpy(b8->Buffer, bytes, length);
        return FAILURE;
    }

    return SUCCESS;
}

Status B16_Set(B16 *b16, const B* bytes, U16 length){
    if(b16 == NULL){
        return FAILURE;
    }

    if(length == 0 || bytes == NULL){
        b16->Length = 0;
    }else if(length <= b16->Size){
        memcpy(b16->Buffer, bytes, length);
    }else{
        length = b16->Size;
        memcpy(b16->Buffer, bytes, length);
        return FAILURE;
    }

    return SUCCESS;
}

Status B32_Set(B32 *b32, const B* bytes, U32 length){
    if(b32 == NULL){
        return FAILURE;
    }

    if(length == 0 || bytes == NULL){
        b32->Length = 0;
    }else if(length <= b32->Size){
        memcpy(b32->Buffer, bytes, length);
    }else{
        length = b32->Size;
        memcpy(b32->Buffer, bytes, length);
        return FAILURE;
    }

    return SUCCESS;
}

Status B64_Set(B64 *b64, const B* bytes, U64 length){
    if(b64 == NULL){
        return FAILURE;
    }

    if(length == 0 || bytes == NULL){
        b64->Length = 0;
    }else if(length <= b64->Size){
        memcpy(b64->Buffer, bytes, length);
    }else{
        length = b64->Size;
        memcpy(b64->Buffer, bytes, length);
        return FAILURE;
    }

    return SUCCESS;
}

Status BT_Set(BT *bt, const B* bytes, UT length){
    if(bt == NULL){
        return FAILURE;
    }

    if(length == 0 || bytes == NULL){
        bt->Length = 0;
    }else if(length <= bt->Size){
        memcpy(bt->Buffer, bytes, length);
    }else{
        length = bt->Size;
        memcpy(bt->Buffer, bytes, length);
        return FAILURE;
    }

    return SUCCESS;
}

Status B8_Del(B8 *b8){
    if(b8 == NULL){
        return FAILURE;
    }

    if(b8->Buffer != NULL){
        free(b8->Buffer);
        b8->Buffer = NULL;
    }
    b8->Size = 0;
    b8->Length = 0;

    return SUCCESS;
}

Status B16_Del(B16 *b16){
    if(b16 == NULL){
        return FAILURE;
    }

    if(b16->Buffer != NULL){
        free(b16->Buffer);
        b16->Buffer = NULL;
    }
    b16->Size = 0;
    b16->Length = 0;

    return SUCCESS;
}

Status B32_Del(B32 *b32){
    if(b32 == NULL){
        return FAILURE;
    }

    if(b32->Buffer != NULL){
        free(b32->Buffer);
        b32->Buffer = NULL;
    }
    b32->Size = 0;
    b32->Length = 0;

    return SUCCESS;
}

Status B64_Del(B64 *b64){
    if(b64 == NULL){
        return FAILURE;
    }

    if(b64->Buffer != NULL){
        free(b64->Buffer);
        b64->Buffer = NULL;
    }
    b64->Size = 0;
    b64->Length = 0;

    return SUCCESS;
}

Status BT_Del(BT *bt){
    if(bt == NULL){
        return FAILURE;
    }

    if(bt->Buffer != NULL){
        free(bt->Buffer);
        bt->Buffer = NULL;
    }
    bt->Size = 0;
    bt->Length = 0;

    return SUCCESS;
}




Status Now(Time t){
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);

    S32 year, month, day, hour, minute, second;
    year = timeinfo->tm_year + 1900;
    month = timeinfo->tm_mon + 1;
    day = timeinfo->tm_mday;
    hour = timeinfo->tm_hour;
    minute = timeinfo->tm_min;
    second = timeinfo->tm_sec;

    snprintf(t, 20, "%04d/%02d/%02d/%02d:%02d:%02d", year, month, day, hour, minute, second);
    return SUCCESS;
}




















