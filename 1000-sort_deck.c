#include "deck.h"

int compare_strings(const char *str1, const char *str2);
char get_card_value(deck_node_t *card);
void sort_deck_by_kind(deck_node_t **deck);
void sort_deck_by_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * compare_strings - Compare two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if str1 == str2
 *         Negative byte difference if str1 < str2
 */
int compare_strings(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * get_card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
char get_card_value(deck_node_t *card)
{
	if (compare_strings(card->card->value, "Ace") == 0)
		return (0);
	if (compare_strings(card->card->value, "1") == 0)
		return (1);
	if (compare_strings(card->card->value, "2") == 0)
		return (2);
	if (compare_strings(card->card->value, "3") == 0)
		return (3);
	if (compare_strings(card->card->value, "4") == 0)
		return (4);
	if (compare_strings(card->card->value, "5") == 0)
		return (5);
	if (compare_strings(card->card->value, "6") == 0)
		return (6);
	if (compare_strings(card->card->value, "7") == 0)
		return (7);
	if (compare_strings(card->card->value, "8") == 0)
		return (8);
	if (compare_strings(card->card->value, "9") == 0)
		return (9);
	if (compare_strings(card->card->value, "10") == 0)
		return (10);
	if (compare_strings(card->card->value, "Jack") == 0)
		return (11);
	if (compare_strings(card->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * sort_deck_by_kind - Sort a deck of cards from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && insert->card->kind > iter->card->kind)
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck_by_value - Sort a deck of cards sorted from
 *                      spades to diamonds from ace to king.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck_by_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *tmp;

	for (iter = (*deck)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
			insert->card->kind == iter->card->kind &&
			get_card_value(insert) > get_card_value(iter))
		{
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	sort_deck_by_kind(deck);
	sort_deck_by_value(deck);
}
