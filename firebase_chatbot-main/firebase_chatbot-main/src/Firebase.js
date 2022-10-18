import firebase from 'firebase';

const config = {
    projectId: 'superchat295',
    apiKey: 'AIzaSyDVHv2Gu3U8vsi1X5tTf1dQiq_qxNIi-O8',
    databaseURL: 'https://superchat295-default-rtdb.asia-southeast1.firebasedatabase.app'
  };
firebase.initializeApp(config);

export default firebase;