#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

node_t *add_inorder(node_t *list, node_t *new)
{
    // TODO: Complete the function.
    
    printf("called");
    
    if (list == NULL || list -> val -> start_date >= new -> val -> start_date){
        //printf("DSDAFSFCF");
        list = new;
        //printf("%s\n", list -> val -> start_date);
    }
    
    else{
        node_t *current = list;
       
        struct tm date_1 = {0};
        struct tm date_2 = {0};
        memset(&date_1, 0, sizeof(struct tm));
        sscanf(current -> val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        memset(&date_2, 0, sizeof(struct tm));
        sscanf(new -> val -> start_date, "%4d%2d%2dT", &date_2.tm_year, &date_2.tm_mon, &date_2.tm_mday);
        date_1.tm_year -= 1900;
        date_1.tm_mon -= 1;
        date_2.tm_year -= 1900;
        date_2.tm_mon -= 1;
        //printf("hjlh%f", difftime(mktime(&date_1), mktime(&date_2)));
        if (current -> next == NULL){
            if (difftime(mktime(&date_1), mktime(&date_2)) >= 0){
                new -> next = list;
                list = new;
               
            }
            else{
                list -> next = new;
            }    
        }
        
        while (current -> next != NULL && difftime(mktime(&date_1), mktime(&date_2)) < 0){
            
            current = current -> next;
        }
        new -> next = current -> next;
        current->next = new;
        
    
    } 
    
    return list;
}



###############################################################






node_t *current = list;

    struct tm date_1 = {0};
    struct tm date_2 = {0};
    if (list != NULL){
        memset(&date_1, 0, sizeof(struct tm));
        sscanf(list ->  val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        memset(&date_2, 0, sizeof(struct tm));
        sscanf(new -> val -> start_date, "%4d%2d%2dT", &date_2.tm_year, &date_2.tm_mon, &date_2.tm_mday);
    }
    

    if (list == NULL || difftime(mktime(&date_2), mktime(&date_1)) <= 0){
        
        new->next = list;
        list = new;
        //printf("first in list - %s\n", list->val->description);


        return list;
    }
    /*
    if (list->next == NULL){
        printf("called");
        struct tm date_1 = {0};
        struct tm date_2 = {0};
        memset(&date_1, 0, sizeof(struct tm));
        sscanf(list -> val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        memset(&date_2, 0, sizeof(struct tm));
        sscanf(new -> val -> start_date, "%4d%2d%2dT", &date_2.tm_year, &date_2.tm_mon, &date_2.tm_mday);


        if (difftime(mktime(&date_1), mktime(&date_2)) >= 0){
            list = add_front(list, new);
            return list;
        }
        else{
            list = add_end(list, new);
            return list;
        }
    }
    */
    //printf("%s\n", list->val->description);
    memset(&date_1, 0, sizeof(struct tm));
    sscanf(current->next ->  val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
    memset(&date_2, 0, sizeof(struct tm));
    sscanf(new -> val -> start_date, "%4d%2d%2dT", &date_2.tm_year, &date_2.tm_mon, &date_2.tm_mday);
    int count = 0;

    node_t *s = list;
    while (s != NULL){
        printf("%s\n", s->val->description);
        s = s->next;
    }
    printf("new list \n");
    
    
    while (current->next != NULL && count == 0){
        if (date_1.tm_mday < date_2.tm_mday){
            count = 1;
        }
        
        if (date_1.tm_mday == date_2.tm_mday){
            
            if (date_1.tm_mon < date_2.tm_mon){
                count = 1;
            }

            if (date_1.tm_mon == date_2.tm_mon){
                
                if (date_1.tm_year < date_2.tm_year){
                    count = 1;
                }
                
                if (date_1.tm_year == date_2.tm_year){
                    count = 1;
                }

            }

        }  
        
        printf("%d/%d/%d  - %d/%d/%d = %f\n", date_1.tm_mon, date_1.tm_mday, date_1.tm_year, date_2.tm_mon, date_2.tm_mday, date_2.tm_year, difftime(mktime(&date_1), mktime(&date_2)));
        sscanf(current->next-> val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        current = current->next;
        count = 0;
        
       
    }
    /*
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    node_t *a = current;
     while (a != NULL){
        printf("%s\n", a->val->description);
        a = a->next;
    }
    
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    
    

    a = new;
     while (a != NULL){
        printf("%s\n", a->val->description);
        a = a->next;
    }

    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    */
    
    
    new->next = current->next;
    //new_copy->next = current;
    
    current->next = new;
    
    
    
    
    
    
    
    
    s = current;
    while (s != NULL){
        printf("%s\n", s->val->description);
        s = s->next;
    }
    printf("next list \n");
    printf("\n");
    
    return list;























    ####################################################################
     node_t *current = list;
    node_t *temp = NULL;
    
    struct tm date_1 = {0};
    struct tm date_2 = {0};
    struct tm date_3 = {0};
    if (list != NULL){
        memset(&date_1, 0, sizeof(struct tm));
        sscanf(current ->  val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        memset(&date_2, 0, sizeof(struct tm));
        sscanf(new -> val -> start_date, "%4d%2d%2dT", &date_2.tm_year, &date_2.tm_mon, &date_2.tm_mday);
    }
    if (list == NULL && (difftime(mktime(&date_1), mktime(&date_2)) == 0)){
        list = new;
        list->next = NULL;
        return list;
    }
    
    if (list->next == NULL){
        new->next = list->next;
        list->next = new;
        return list;
    }
    /*
    node_t *a = list;
     while (a != NULL){
        printf("%s\n", a->val->description);
        a = a->next;
    }
    */
    while (current->next != NULL && (difftime(mktime(&date_1), mktime(&date_2)) <= 0)){
        //printf("%d/%d/%d  - %d/%d/%d = %f\n", date_1.tm_mon, date_1.tm_mday, date_1.tm_year, date_2.tm_mon, date_2.tm_mday, date_2.tm_year, difftime(mktime(&date_1), mktime(&date_2)));
        //printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAA%s\n", current->val->description);
        /*
        if (current->next == NULL){
            break;
        }
        memset(&date_3, 0, sizeof(struct tm));
        
        sscanf(current->next->  val -> start_date, "%4d%2d%2dT", &date_3.tm_year, &date_3.tm_mon, &date_3.tm_mday);
        sscanf(current ->  val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
        
        if ((difftime(mktime(&date_3), mktime(&date_2)) <= 0)){
            printf("Broke\n");
            break;
            
        }
        */
        memset(&date_3, 0, sizeof(struct tm));
        sscanf(current->next->  val -> start_date, "%4d%2d%2dT", &date_3.tm_year, &date_3.tm_mon, &date_3.tm_mday);
        sscanf(current ->  val -> start_date, "%4d%2d%2dT", &date_1.tm_year, &date_1.tm_mon, &date_1.tm_mday);
    
        if ((difftime(mktime(&date_3), mktime(&date_2)) >= 0)){
            break;
        }
        
        

        current = current->next;
    }
    /*
    if ((difftime(mktime(&date_1), mktime(&date_3)) == 0)){
        current->next->next = new;
        return current;
    }
    */
    //printf("new\n");
    new->next = current->next;
    current->next = new;
    
    return list;