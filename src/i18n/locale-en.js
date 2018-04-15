const locales = {
  'COMMON': {
    'HOME': 'Home',
    'DEPLOY': 'Deploy',
    'NO_DATA': 'There is no book with this title.',
    'TYPE_SOMETHING': 'You need to type book title'
  },
  'PLACEHOLDERS': {
    'SEARCH': 'Search Books'
  }
};


export default function(string) {
  const data = string.split('.');
  let locale = locales;
  for(let property of data) {
    locale = locale[property];
  }
  return locale;
}